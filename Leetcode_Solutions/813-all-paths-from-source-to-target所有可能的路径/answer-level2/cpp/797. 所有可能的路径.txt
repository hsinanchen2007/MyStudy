### 解题思路
很明显的dfs

### 代码

```cpp
class Solution {
public:
    vector<vector<int>>res;
    vector<int>tmp,book;
    void dfs(vector<vector<int>>& graph,int pos,int n){
        if(pos==n-1){
            res.push_back(tmp);
            return ;
        }
        for(int i=0;i<graph[pos].size();i++){
            if(book[graph[pos][i]]==0){
                book[graph[pos][i]]=1;
                tmp.push_back(graph[pos][i]);
                dfs(graph,graph[pos][i],n);
                book[graph[pos][i]]=0;
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        book=vector<int>(graph.size(),0);
        book[0]=1;
        tmp.push_back(0);
        dfs(graph,0,graph.size());
        return res;
    }
};
```