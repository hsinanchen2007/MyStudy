
这道题没什么坑，直接DFS可过。

```c++
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> vis(rooms.size(), false);
        dfs(rooms, 0, vis);
        return all_of(vis.begin(), vis.end(), [](bool x){return x == true;});
    }
private:
    void dfs(vector<vector<int>>& rooms, int room, vector<bool>& vis){
        vis[room] = true;
        for(auto it : rooms[room]){
            if(vis[it]) continue;
            dfs(rooms, it, vis);
        }
        return ;
    }
};
```
