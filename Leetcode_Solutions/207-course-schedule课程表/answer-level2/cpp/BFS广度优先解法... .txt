### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> map;
        vector<int> degree(numCourses); // 入度

        for (auto pair : prerequisites) {
            map[pair[1]].emplace_back(pair[0]);
            degree[pair[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!degree[i]) q.emplace(i);

        int cnt = 0;
        while (!q.empty()) {
            int n = q.front(); q.pop();
            cnt++;
            
            for (auto x : map[n]) {
                degree[x]--;
                if (!degree[x]) q.emplace(x);
            }
        }

        return cnt == numCourses;
    }
};
```