#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> suffixArrayNative(string S) {
    int n = S.length(); // evitando agregar el $ como sufijo
    vector<string> sa;
    vector<int> A(n);
    S = S + "$";
    for(int i = 0; i < n; i++) {
        sa.push_back(S.substr(n-i-1, i+1));
        sort(sa.begin(), sa.end());
    }
    for(int i = 0; i < n; i++) {
        A[i] = n - sa[i].size() + 1;
    }
    return A;
}

int main(){

    string S;
    getline(cin, S);
    
    vector<int> arr = suffixArrayNative(S);
    
    for (int pos : arr) {
        cout << pos << "\n";
    }
    
    return 0;
}
