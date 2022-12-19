### 解题思路
dfs

### 代码

```cpp
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,int> gone;
        bool ret=true;
        for(int i=0;i<graph.size();i++){
            if(!gone.count(i)){
                gone.insert({i,true});
                if(!dfs(graph,gone,i,false)) {
                    ret=false;break;
                }
            }
        }
        return ret;
    }
    bool dfs(vector<vector<int>>& graph,unordered_map<int,int>& gone,int row,bool curFlag){
        for(int i=0;i<graph[row].size();i++){
            int idx=graph[row][i];
            if(gone.count(idx)){
                if(gone[idx]==curFlag) continue;
                else return false;
            }else{
                gone.insert({idx,curFlag});
                if(dfs(graph,gone,idx,!curFlag)) continue;
                else return false;
            }
        }
        return true;
    }
};
```