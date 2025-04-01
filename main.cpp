
/*
 * SonarQube, open source software quality management tool.
 * Copyright (C) 2008-2013 SonarSource
 * http://github.com/SonarOpenCommunity/sonar-cxx
 *
 * SonarQube is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * SonarQube is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 * 
 * Author: Adrian Salazar 
 * Date: 2025-3-31
 * Description: Suffix Array Native Implementation
 */

 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> suffix_array_native(string S) {
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
    
    vector<int> arr = suffix_array_native(S);
    
    for (int pos : arr) {
        cout << pos << "\n";
    }
    
    return 0;
}


