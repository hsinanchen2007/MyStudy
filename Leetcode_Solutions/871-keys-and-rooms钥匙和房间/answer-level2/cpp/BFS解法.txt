### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        const int N = rooms.size();
        
        vector<bool> visited(N, false);

        queue<int> q;
        q.emplace(0);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            visited[cur] = true;

            for (int n : rooms[cur]) {
                if (!visited[n]) q.emplace(n);
            }
        }

        for (int i = 0; i < N; i++)
            if (!visited[i]) return false;

        return true;
    }
};
```