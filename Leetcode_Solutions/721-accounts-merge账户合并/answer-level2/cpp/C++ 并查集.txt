### 解题思路
笨办法。
### 代码

```cpp
class Solution {
public:
    int find(int x,vector<int> &parent){
            if(x!=parent[x]) parent[x] = find(parent[x],parent);
            return parent[x];
        }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        int n = accounts.size();
        vector<int> parent(n);
        for(int i = 0; i< n;i++) parent[i] = i;
        for(int i = 0; i< n;i++){
            int m = accounts[i].size();
            for(int j=1;j<m;j++){
                if(mp.count(accounts[i][j])){
                    parent[find(parent[i],parent)] =find(mp[accounts[i][j]],parent);
                    accounts[i][j]=" ";
                }
                else mp[accounts[i][j]] = parent[i];
            } 
        }
        vector<vector<string>> ans;
        for(int i = 0; i< n;i++){
            if(parent[i] != i){
                int tar = find(i,parent);
                int m = accounts[i].size();
                for(int j = 1; j<m;j++){
                    accounts[tar].push_back(accounts[i][j]);
                }
            }
        }
        for(int i = 0; i< n;i++){
            if(parent[i] == i)
            {  
                accounts[i].erase(remove(accounts[i].begin(), accounts[i].end(), " "), accounts[i].end());
                sort(accounts[i].begin()+1,accounts[i].end());
                ans.push_back(accounts[i]);
            } 
        }
        return ans;
    }
};
```