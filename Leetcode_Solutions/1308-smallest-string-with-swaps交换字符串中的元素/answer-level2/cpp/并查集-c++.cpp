```
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<int>parent = construct_parent(n); 
        for(int i = 0; i < pairs.size(); ++i)
        {
            p_union(parent, pairs[i][0], pairs[i][1]);
        }
        map<int, vector<int>> idx_union;
        for(int i = 0; i < parent.size(); ++i)
        {
            idx_union[find_parent(parent, i)].push_back(i);
        }
        for(auto it = idx_union.begin(); it != idx_union.end(); ++it)
        {
            vector<int> connect = it->second;
            string subseq;
            for(int i : connect)
            {
                subseq += s[i];
            }  
            sort(subseq.begin(), subseq.end());
            sort(connect.begin(), connect.end());
            for(int i=0; i < connect.size(); ++i)
            {
                s[connect[i]] = subseq[i];
            }  

        }
        return s;  
    }
    void p_union(vector<int>& parent, int i, int j){
        int p_i = find_parent(parent, i);
        int p_j = find_parent(parent, j);
        parent[p_j] = p_i;
    }
    int find_parent(vector<int>& parent, int i){
        if(parent[i] != i)
        {
            parent[i] = find_parent(parent, parent[i]);
        }
        return parent[i];
    }
    vector<int> construct_parent(int n){
        vector<int> parent(n,0);
        for(int i = 0; i < n ; ++i)
        {
            parent[i] = i;
        }
        return parent;
    } 

};
```
