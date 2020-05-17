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
    this->maxChild=10000;   
    this->maxLeafnode=9999;
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
        else{   //not full case
            vector<int> tmpkey(cursor->keys);
            vector<int> tmpdata(cursor->data);
            node* newnode;

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

            

        }
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


