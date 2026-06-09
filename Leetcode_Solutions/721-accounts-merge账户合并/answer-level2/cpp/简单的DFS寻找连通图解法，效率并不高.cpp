### 解题思路
这个题跟547.朋友圈比较类似，可以看做图的连通性问题。
把所有email当做图的结点来看，可以画出一个图，那么问题抽象为输出所有的联通图，这类问题其实并查集是最合适的解法。
但是DFS思路更加简单好动。
首先用email做节点，邻接图法建图。同时还要记录email->name的索引map。
然后遍历每个email节点，做DFS，这样就能获取到此email相连的所有email，这些email属于同一个人。一次DFS能够获取一个连通图，这个联通图中所有email属于同一个name。
这样就能找到每个name对应的所有email

### 代码

```cpp
class Solution {
public:
    void dfs(string &curNode, unordered_map<string, unordered_set<string>> &graph, vector<string> &curRecord) {
        if (visited.count(curNode)) {
            return;
        }
        visited.insert(curNode);
        curRecord.emplace_back(curNode);
        for (auto email : graph[curNode]) {
            if (!visited.count(email)) {
                dfs(email, graph, curRecord);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToNameMap;
        unordered_map<string, unordered_set<string>> graph;

        // 建图
        for (auto account : accounts) {
            string name = account[0];
            //printf("cur record: %s -- size=%d\n", name.c_str(), account.size());
            for (int i = 1; i < account.size(); i++) {
                // 记录email->name的映射表
                emailToNameMap[account[i]] = name;
                // 建图, 邻接表
                for (int j = 1; j < account.size(); j++) {
                    graph[account[i]].insert(account[j]);
                }
            }
        }

        for (auto node : graph) {
            if (visited.count(node.first)) {
                continue;
            }
            string email = node.first;
            string name = emailToNameMap[email];
            vector<string> onerecord;
            onerecord.emplace_back(name);
            dfs(email, graph, onerecord);
            sort(onerecord.begin(), onerecord.end());
            ans.emplace_back(onerecord);
        }
        return ans;
    }
private:
    unordered_set<string> visited;
    vector<vector<string>> ans;
};
```