思路很简单，回溯加剪枝，只能用于图中的有向无环图
但是我觉得终止条件应该是遇到最后一个节点（使用最后一个节点是空好像也能判断）
总之晕晕的过了
```
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<bool> visit(graph.size(),false);
        dfs(res,0,graph,{},visit);
        return res;
    }
    void dfs(vector<vector<int>>& res,int start,vector<vector<int>>& graph,vector<int> temp,vector<bool>visit){
        if(graph[start].size() == 0 || temp.size()>=graph.size()){
            res.push_back(temp);
            return;
        }
        if(visit[start]== false)
            temp.push_back(start);
        //visit[start]  = true;
        for(int i = 0;i < graph[start].size();i++){
            if(visit[graph[start][i]])
                continue;
            else{
                temp.push_back(graph[start][i]);
                visit[graph[start][i]] = true;
                dfs(res,graph[start][i],graph,temp,visit);
                temp.pop_back();
                visit[graph[start][i]] = false;
            }
        }
    }
};
```
