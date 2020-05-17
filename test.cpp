#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0), ios::sync_with_stdio(0);
    
    vector<int> rec;
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);
    rec.push_back(1);

    vector<int> rec2(rec);

    for(auto &t:rec2){
        cout<<t<<endl;
    }

    return 0;
}