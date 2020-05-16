#include "index.h"

using namespace std;

class Index{
    int num_rows;
    vector<int> key;
    vector<int> value;
    
    Index(const int num_rows,const vector<int> &key,const vector<int> &value);

    void key_query();
    void range_query(vector<int> query_keys);
    void range_query(vector<pair<int,int> > query_pairs);
    void clear_index();
};

//Build index when index constructor is called
Index::Index(const int num_rows,const vector<int> &key,const vector<int> &value){
    this->num_rows=num_rows;
    this->key=key;
    this->value=value;
}

