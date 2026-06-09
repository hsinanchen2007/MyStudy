### 解题思路
从start开始深度优先或广度优先搜索，如果使用邻接矩阵存储图的话，有些用例会超出内存限制，所以使用邻接表存储图。

### 代码
DFS
```cpp
class Solution {
    vector<bool> viewed;
    vector<vector<int>> adList;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        viewed = vector<bool>(n,0);
        adList = vector(n,vector<int>(1,-1));
        for (int i=0;i<graph.size();i++){
            adList[graph[i][0]].push_back(graph[i][1]);
        }
        return search(start,target);
    }

    bool search(int start,int target){
        viewed[start] = 1;
        bool result = 0;
        for(int i=1;i<adList[start].size();i++){
            if (viewed[adList[start][i]]==0){
                if(adList[start][i]==target){
                    viewed[adList[start][i]] =1 ;
                    return 1;
                }
                result = search(adList[start][i],target);
                if(result==1)
                    break;
            }
        }
        return result;
    }
};
```
BFS
class Solution {
    vector<bool> viewed;
    vector<vector<int>> adList;
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        viewed = vector<bool>(n,0);
        adList = vector(n,vector<int>(1,-1));
        for (int i=0;i<graph.size();i++){
            adList[graph[i][0]].push_back(graph[i][1]);
        }
        return search(start,target);
    }

    bool search(int start,int target){
        queue<int> q;
        int v;
        viewed[start] =1;
        q.push(start);
        while(!q.empty()){
            v = q.front();
            q.pop();
            for(int i=1;i<adList[v].size();i++){
                if(viewed[adList[v][i]]==0){
                    viewed[adList[v][i]] = 1;
                    if(adList[v][i]==target){
                        return 1;
                    }
                    else{
                        q.push(adList[v][i]);
                    }
                }
            }
        }
        return 0;
    }
};