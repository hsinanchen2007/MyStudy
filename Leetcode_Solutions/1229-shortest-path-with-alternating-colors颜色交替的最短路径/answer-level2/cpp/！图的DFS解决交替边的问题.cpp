### 解题思路
首先感谢题解中的DFS方法！！
思路：
1、对红边和蓝边分别建立邻接表；
2、利用颜色，把这两个邻接表合在一起，变成g；
3、分别从蓝色和红色开始DFS；
4、比较从蓝色和红色开始的值哪个更小，就取为结果。

### 代码

```cpp
class Solution {
public:
    const int INF = 1e8;
    void dfs(vector<vector<vector<int> > >& g, int col, int i, vector<vector<int> >& res) {
        for (int t=0; t<g[col][i].size(); t++){
            if (res[i][col]+1<res[g[col][i][t]][!col]){//对应节点的值可以更新
                res[g[col][i][t]][!col]=res[i][col]+1;
                dfs(g, !col, g[col][i][t], res);//更新下去
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<int> > rg(n);
        vector<vector<int> > bg(n);
        for (int i=0; i<red_edges.size(); i++) rg[red_edges[i][0]].push_back(red_edges[i][1]);//建立红色边的邻接表
        for (int i=0; i<blue_edges.size(); i++) bg[blue_edges[i][0]].push_back(blue_edges[i][1]);//建立蓝色边的邻接表
        vector<vector<vector<int> > > g{rg, bg};//第一维代表颜色，第二三维代表对应颜色的邻接表
        vector<vector<int> > res(n, {INF, INF});//所有结果置为INF
        res[0] = {0, 0};//初始化0节点
        dfs(g, 0, 0, res);//计算从红色开始的res
        dfs(g, 1, 0, res);//计算从蓝色开始的res
        vector<int> out(n);
        for (int i = 0; i < n; ++i) {
            out[i] = min(res[i][0], res[i][1]);//两个中取最小
            if (out[i] == INF) out[i] = -1;
        }
        return out;
    }
};

```