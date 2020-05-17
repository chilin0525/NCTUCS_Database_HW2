#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include "index.h"
using namespace std;

//Build index when index constructor is called

node::node(){
    this->isleaf=false;
    this->next=NULL;
}

Bplustree::Bplustree(){
    this->root=NULL;
    this->maxChild=10;   
    this->maxLeafnode=10;
}

Index::Index(const int num_rows,const vector<int> &key,const vector<int> &value){
    for(int i=1;i<=num_rows;++i){
       bptree.insert(key[i],value[i]);
    }
}

void Bplustree::insert(int key,int value){
    if(root==NULL){
        root=new node;
        root->isleaf=true;
        root->keys.emplace_back(key);
        root->data.emplace_back(value);
    }
    else{
        node* cursor=root;
        node* parent=NULL;

        while(cursor->isleaf==false){  //until find leaf node
            parent=cursor;
            int index=upper_bound(cursor->keys.begin(),cursor->keys.end(),key)-cursor->keys.begin();
            cursor = cursor -> prt_to_subtree[index];
        }

        if(cursor->keys.size() < maxLeafnode){
            int index=upper_bound(cursor->keys.begin(),cursor->keys.end(),key)-cursor->keys.begin();
            for(int i=cursor->keys.size();i>index;--i){
                cursor->keys[i]=cursor->keys[i-1];
                cursor->data[i]=cursor->data[i-1];
            }
            cursor->keys[index]=key;
            cursor->data[index]=value;
        }
        else{   //full case
            vector<int> tmpkey(cursor->keys);
            vector<int> tmpdata(cursor->data);
            node* newnode;
            newnode->isleaf=true;

            int index=upper_bound(cursor->keys.begin(),cursor->keys.end(),key)-cursor->keys.begin();
            tmpkey.push_back(key);
            tmpdata.push_back(value);

            // key and value push into tmp node 
            if(index!=cursor->keys.size()-1){                    //not end of vector -> shift
                for(int j=cursor->keys.size()-1;j>index;--j){
                    tmpkey[j]=tmpkey[j-1];
                    tmpdata[j]=tmpdata[j-1];
                }
                tmpkey[index]=key;
                tmpdata[index]=value;
            }

            // swap pointer
            // 1 --> 3
            // 1 -> 2 -> 3
            node* tmp=cursor->next;
            cursor->next=newnode;
            newnode->next=tmp;

            // cursor->keys old:
            // newnode : 
            cursor->keys.resize(maxLeafnode/2+1);
            cursor->data.resize(maxLeafnode/2+1);
            
            for(int i=0;i<=maxLeafnode/2;++i){
                cursor->keys[i]=tmpkey[i];
                cursor->data[i]=tmpdata[i];
            }

            for(int i=maxLeafnode/2+1;i<tmpkey.size();++i){
                newnode->keys.emplace_back(tmpkey[i]);
                newnode->data.emplace_back(tmpdata[i]);
            }
            
            if(cursor==root){
                node* newroot=new node;
                newroot->keys.push_back(newnode->keys[0]);
                newroot->prt_to_subtree.push_back(cursor);
                newroot->prt_to_subtree.push_back(newnode);
            }
            else{
                split(newnode->keys[0],parent,newnode);
            }
        }
    }
}

void Bplustree::split(int key,node *parent,node *child){
    if(parent->keys.size()+1<maxChild){
        int index=upper_bound(parent->keys.begin(),parent->keys.end(),key)-parent->keys.begin();
        parent->keys.push_back(key);
        parent->prt_to_subtree.push_back(child);

        if(index!=parent->keys.size()-1){
            for(int i=parent->keys.size()-1;i>index;--i){
                parent->keys[i]=parent->keys[i-1];
            }
        }
        parent->keys[index]=key;
        parent->prt_to_subtree.push_back(child);
    }
    else{ // parent will full

    }
}

void Index::key_query(const vector<int> &query_keys){
    return ;
}

void Index::range_query(const vector<pair<int,int> > &query_pairs){
    return ;
}


void Index::clear_index(){

    // use destructor to clear memory used
    
    return ;
}


