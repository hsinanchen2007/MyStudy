### 解题思路
深度优先搜索算法//之后再复盘

### 代码

```cpp
class Solution {
public:
    bool dfs(const vector<vector<int>>& graph, vector<int>& cols, int i, int col) {
        cols[i] = col;          //遍历第i个点的情况，直接先将第i个点染色
        for (auto j : graph[i]) {
            if (cols[j] == cols[i]) return false;//判断与第i个点相连的点是否不同，即判断其是否也已经被染色
            if (cols[j] == 0 && !dfs(graph, cols, j, -col)) return false;//如果没有被染色，则递归判断第j个点的情况
                                                      //如果第j个点与其相连的点已经被染色，则返回false
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> cols(N, 0); //新建一个数组来记录染色情况：初始都为0
        for (int i = 0; i < N; ++i) {//从每个点开始遍历，
            if (cols[i] == 0 && !dfs(graph, cols, i, 1)) {
                return false;
            }
        }
        return true;
    }
};

```