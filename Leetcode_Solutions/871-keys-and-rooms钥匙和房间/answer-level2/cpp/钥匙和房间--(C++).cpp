### 解题思路
解题: 题目一看就是递归，然后需要记住记录一个visited数组(这是用hash_map,效果一样)，否则会陷入来回dfs的死循环。
(1) 递归函数一般是这种形式：dfs(vector<int> item, int index),item记录每层节点，index笔试遍历的数组的位置
(2) 有时候串需要表示前后就是用int left, int right组合了。总共就那么几种形式dfs(vector<int> item, int left, int right)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> rooms;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // 明显的递归
        this->rooms = rooms;
        vector<int> path;
        map<int, bool> hash_map; // <index, bool>
        dfs(path, hash_map, 0);
        // for (int i = 0; i < path.size(); i++) {
        //     cout << path[i] << endl;
        // }
        if (path.size() == rooms.size())
            return true;
        return false;
    }

    void dfs(vector<int>& path, map<int, bool>& hash_map, int index) {
        if (hash_map[index] == true)
            return;
        path.push_back(index);
        hash_map[index] = true;

        for (int i = 0; i < ((this->rooms)[index]).size(); i++) {
            dfs(path, hash_map, rooms[index][i]);
        }
        
    }
};
```