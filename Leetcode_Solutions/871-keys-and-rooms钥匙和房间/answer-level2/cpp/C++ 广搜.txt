### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/24f1bb19c220b1f305a1e46e7179d6b06238bc8f69d90ee28c00f1a9ecb8ba7e-image.png)

### 代码

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visitedRooms(rooms.size(),-1);
        queue<int> toVisistRooms;
        visitedRooms[0] = 1;
        for( int key : rooms[0]) {
            toVisistRooms.emplace(key);
        }
        while (!toVisistRooms.empty()) {
            int toVisitRooom = toVisistRooms.front();
            toVisistRooms.pop();
            if (visitedRooms[toVisitRooom] == 1) {
                continue;
            }
            visitedRooms[toVisitRooom] = 1;
            for (int key : rooms[toVisitRooom]){
                toVisistRooms.emplace(key);
            }
        }
        return find(visitedRooms.begin(),visitedRooms.end(),-1) == visitedRooms.end();
    };
};
```