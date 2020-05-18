#include <utility>
#include <vector>
using namespace std;

class node{
    public:    
        pair<int,int> pair_key_value;
        vector<int>   keys;
        vector<int>   data;
        vector<node*> prt_to_subtree;
        bool isleaf;
        node* next;

        node();
        node(int key,int value);
        ~node();
};

class Bplustree{
    public:
        node* root;
        int maxChild;
        int maxLeafnode;
        Bplustree();
        void insert(int,int);
        node** ancestor(node* root,node* child);
        void split(int key,node** parent,node** child);
        int  search(const int);
        int range_search(const int,const int);
        ~Bplustree();
};

class Index{
    public:
        Bplustree bptree;

        Index(const int num_rows,const vector<int> &key,const vector<int> &value);

        void key_query(const vector<int> &query_keys);
        void range_query(const vector<pair<int,int> > &query_pairs);
        void clear_index();
};
