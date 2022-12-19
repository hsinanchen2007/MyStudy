### 解题思路
直接用bfs解决。
每次访问一间房间的时候，将它里面的钥匙放入数组，并且记录当前访问的房间。
下次再遍历已有的钥匙的房间，当钥匙用光的时候，判断是否已经遍历了所有房间。

### 代码

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if (rooms.size() <= 1) {
            return true;
        }
        set<int> visited;
        visited.emplace(0);
        queue<int> que;
        for (auto i : rooms[0]) {
            que.push(i);
            visited.emplace(i);
        }
        while (!que.empty()) {
            int n = que.front();
            que.pop();
            for (auto i : rooms[n]) {
                if (visited.count(i) == 0) {
                    que.push(i);
                    visited.emplace(i);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};
```