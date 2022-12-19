### 解题思路
#### BFS
思路主要就是广搜所有钥匙可以打开的房间，一一访问这些房间并把相应的房间号加入已访问房间集合，最后判断已访问房间的数量与总房间数量是否相同。

### 代码

```cpp
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visited;
        queue<int> queue;
        bool res=true;
        
        int len=rooms[0].size();
        int roomCount=rooms.size();
        for(int i=0; i<len; i++)
            queue.push(rooms[0][i]);
        visited.insert(0);
        
        while(!queue.empty()){
            int roomIndex=queue.front();
            queue.pop();
            
            if(findElem(roomIndex,visited)){
               continue; 
            }
            visited.insert(roomIndex);
            for(int i=0; i<rooms[roomIndex].size(); i++){
                if(!findElem(rooms[roomIndex][i],visited))
                    queue.push(rooms[roomIndex][i]);
            }
        }
        if(visited.size() != rooms.size())
            res=false;
        return res;
    }
    bool findElem(int& elem,unordered_set<int>& set){
        if(set.find(elem) == set.end())     
            return false;
        return true;
    }
};
```