## 思路：BFS
### 代码
```c++
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        vector<bool> visited(size);
        queue<int> que;
        que.push(0);
        visited[0] = true;
        while (!que.empty()) {
            vector<int> tmp = rooms[que.front()];
            que.pop();
            for (int i = 0; i < tmp.size(); ++i) {
                if (!visited[tmp[i]]) {
                    visited[tmp[i]] = true;
                    que.push(tmp[i]);
                }
            }
        }
        for (bool v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
};
```
