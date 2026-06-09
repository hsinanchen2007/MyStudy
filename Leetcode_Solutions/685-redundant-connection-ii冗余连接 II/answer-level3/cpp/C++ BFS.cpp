### 解题思路
C++ 暴力BFS 很慢，而且邻接表那里最好使用set。就是想试试BFS，跑的慢就不优化了

### 代码

```cpp
class Solution {
public:

/*
1. 依次从后往前删除边
2. 构造邻接表
3. 找到没有入度的点（根），以此为起点BFS，检查是否每个节点都遍历了
4. 如果成功则返回
*/

    bool BFS(int root, vector<set<int>> &table)
    {
        list<int> stack;
        int cur;
        vector<int> mark;
        int i;

        mark.resize(table.size(), false);

        stack.push_back(root);
        mark[root] = true;
        while (!stack.empty()) {
            cur = stack.front();
            stack.pop_front();

            for (auto it = table[cur].begin(); it != table[cur].end(); ++it) {
                if (mark[*it]) {
                    return false;
                }

                stack.push_back(*it);
                mark[*it] = true;
            }
        }

        for (i = 1; i < mark.size(); ++i) {
            if (!mark[i]) {
                return false;
            }
        }

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> intable;
        // vector<vector<int>> table;
        int i, j;
        int root;
        vector<set<int>> table;

        intable.resize(edges.size() + 1, 0);
        table.resize(edges.size() + 1);

        for (i = 0; i < edges.size(); ++i) {
            table[edges[i][0]].insert(edges[i][1]);
            intable[edges[i][1]] += 1;
        }

        for (i = edges.size() - 1; i >= 0; --i) {
            table[edges[i][0]].erase(edges[i][1]);
            intable[edges[i][1]] -= 1;

            for (j = 1; j < intable.size(); ++j) {
                if (intable[j] == 0) {
                    root = j;
                    break;
                }
            }

            if (BFS(root, table)) {
                return edges[i];
            }

            intable[edges[i][1]] += 1;
            table[edges[i][0]].insert(edges[i][1]);
        }

        return edges[0];
    }
};
```