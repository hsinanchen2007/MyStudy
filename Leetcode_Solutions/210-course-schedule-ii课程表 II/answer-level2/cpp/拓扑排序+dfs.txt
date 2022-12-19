### 解题思路
拓扑排序需要先计算入度
dfs借助了栈

### 代码

```cpp
#if 0
// bfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        unordered_map<int, int> indegree;
        unordered_map<int, vector<int>> adjacency;
        for (int i = 0; i < numCourses; ++i) {
            indegree[i] = 0;
        }
        for (auto each : prerequisites) {
            indegree[each.front()]++;
            adjacency[each.back()].push_back(each.front());
        }

        cout << "the indegree is : " << endl;
        showIndegree(indegree);

        cout << "the adj is : " << endl;
        showAdj(adjacency);

        queue<int> que;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                que.push(i);
            }
        }

        vector<int> result;
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            result.push_back(cur);
            numCourses -= 1;

            for (auto each : adjacency[cur]) {
                if (--indegree[each] == 0) {
                    que.push(each);
                }
            }
        }

        if (numCourses == 0) {
            return result;
        } else {
            return {};
        }
    }
private:
    void showIndegree(const unordered_map<int, int>& degree)
    {
        for (auto each : degree) {
            cout << each.first << "-->" << each.second << endl;
        }
    }
    void showAdj(const unordered_map<int, vector<int>>& adj)
    {
        for (auto each : adj) {
            cout << each.first << "-->";
            for (auto item : each.second) {
                cout << item << "," << endl;
            }
        }
    }
};
#endif

// dfs
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        nums = numCourses;

        for (int i = 0; i < nums; ++i) {
            color.push_back(0);
        }

        for (auto each : prerequisites) {
            adjacency[each.back()].push_back(each.front());
        }

        bool isLoop = false;
        for (int i = 0; i < nums; ++i) {
            isLoop = dfs(i);
            if (isLoop == true) {
                break;
            }
        }

        if (isLoop == true) {
            return {};
        } else {
            vector<int> result;
            while (!order.empty()) {
                result.push_back(order.top());
                order.pop();
            }

            return result;
        }
    }
private:
    int nums;
    vector<int> color;
    unordered_map<int, vector<int>> adjacency;
    stack<int> order;

    bool dfs(int i)
    {
        if (color[i] == 1) {
            return true;
        } else if (color[i] == 2) {
            return false;
        }

        color[i] = 1;

        bool isLoop = false;
        for (auto each : adjacency[i]) {
            isLoop = dfs(each);
            if (isLoop == true) {
                return isLoop;
            }
        }

        color[i] = 2;
        order.push(i);

        return false;
    }
};
```