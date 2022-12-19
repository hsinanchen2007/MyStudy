```
class Solution {
public:
    void dfs(const vector<vector<int> >& rooms, vector<bool>& visited, int i) {
        visited[i] = true;
        for (auto j : rooms[i]) {
            if (!visited[j]) {
                dfs(rooms, visited, j);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int N = rooms.size();
        vector<bool> visited(N, false);
        dfs(rooms, visited, 0);
        return all_of(visited.begin(), visited.end(), [](bool x){return x;});
    }
};
```
![image.png](https://pic.leetcode-cn.com/ffcea551163f48ce0c198fdf76e6d657de961aaf8fd4ae7eea439a8e1a6145b4-image.png)
