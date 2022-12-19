### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        // 记录哪个学生节点被搜过
        vector<int> visit(M.size(), 0);
        // 返回结果，朋友圈总数
        int res = 0;
        // 循环搜索每个学生
        for (int i=0; i<M.size(); i++) {
            // 如果该学生没有被检索过，这个学生所在的朋友圈就是一个独立的朋友圈
            if (visit[i] == 0) {
                // 深度优化搜索，递归方式
                dfs(i, M, visit);
                // 朋友圈总数需要加1，
                res++;
            }
        }
        return res;
    }
    
    // dfs、递归方式
    // u：第u个学生
    // graph：N*N关系矩阵
    // visit：学生节点
    void dfs(int u, vector<vector<int>>& graph, vector<int>& visit) {
        // 访问过的节点标记为1
        visit[u] = 1;
        // 搜索本学生u的朋友关系
        for (int i=0; i<graph[u].size(); i++){
            // 节点未被访问过且是连通的，递归进行深度搜索
            if (visit[i]==0 && graph[u][i]==1)
                dfs(i, graph, visit);
        }
    }
};


#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& graph, vector<int>& visit) {
    visit[u] = 1;
    for (int i=0; i<graph[u].size(); i++){
        if (visit[i]==0 && graph[u][i]==1)
            dfs(i, graph, visit);
    }
}

int findCircleNum(vector<vector<int>>& M) {
    vector<int> visit(M.size(), 0);
    int res = 0;
    for (int i=0; i<M.size(); i++) {
        if (visit[i] == 0) {
            dfs(i, M, visit);
            res++;
        }
    }
    return res;
}

int main() {
    vector<vector<int>> graph = {{1,1,0},
                                 {1,1,0},
                                 {0,0,1}};
    cout << findCircleNum(graph) << endl;
}


```