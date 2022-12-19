### 解题思路

思路：邻接表+BFS
1、首先给定了两种表，可以求出两张表中节点的邻接表，方便后续遍历使用
2、求最短路径一般情况下可以用BFS，这题稍微有点变动的是路径的选择是交替的，这个不算难，只要做好标记，轮流选择即可
3、每次走到一个节点，记录并更新当前节点所花的步数，其实有点记忆化数组的味道
4、为了避免路径重复走，可以记录访问路径a->b时所耗费的步数，在步数减少的时候需要重新加回队列，其实也就是Dij算法
5、如果不使用mem每次记录以及访问路径的步数刷新的话，也就是普通的BFS遍历，每次确定target也是可以的，本题不会超时，不过耗时也在400ms以上了

32ms 17.2M
--- wangtao HW-2020/3/9

### 代码

```cpp
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        // 0代表红边，1代表蓝边
        vector<map<int, vector<int>>> edges(2);
        vector<int> ans(n, INT_MAX);
        for (int i = 0; i < red_edges.size(); i++) {
            edges[0][red_edges[i][0]].push_back(red_edges[i][1]);
        }
        for (int i = 0; i < blue_edges.size(); i++) {
            edges[1][blue_edges[i][0]].push_back(blue_edges[i][1]);
        }
        ans[0] = 0;
        // 邻接表OK，遍历求target
        for (int j = 0; j < 2; j++) {
            if (edges[j].count(0) == 0) {
                continue;
            }
            // 选定先手
            vector<map<pair<int, int>, int>> rbvisited(2);
            queue<pair<pair<int, int>, int>> qu;
            for (auto c : edges[j][0]) {
                qu.push({{c, j}, 1});
                rbvisited[j][{0, c}] = 1;
            }
            while(!qu.empty()) {
                pair<pair<int, int>, int> cur = qu.front();
                int val = cur.first.first;
                int index = cur.first.second;
                int step = cur.second;
                qu.pop();

                ans[val] = min(ans[val], step);
                int newindex = (index == 0 ? 1 : 0);
                if (edges[newindex].count(val) != 0) {
                    vector<int> newval = edges[newindex][val];
                    for (int k = 0; k < newval.size(); k++) {
                        if (rbvisited[newindex].count({val, newval[k]}) == 0 || 
                            (rbvisited[newindex].count({val, newval[k]}) == 1 && rbvisited[newindex][{val, newval[k]}] > step+1)) {
                            qu.push({{newval[k], newindex}, step+1});
                            rbvisited[newindex][{val, newval[k]}] = step+1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] == INT_MAX) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};
```