首先判断`room[0]`为空时会分成两种情况：
- 当`room.size() == 1`即房间数量为1时，即使`room[0]`中没有钥匙，那么它已经进入了有且只有的一个房间`room[0]`，返回`true`;
- 否则，当`room.size() > 1`即房间数量多于一个时，那么只能进入`room[0]`，无法再进入其他房间，返回`false`;

然后是一般情况：
- 创建一个`unordered_set<int> visited`用来之后查找该房间是否已经被打开，`vector<int> entered`用来最后查找是否还存在无法进入的房间
- 首先将第0个房间号（即`0`）加入队列`keys`中
- 此后将所在房间号存放在`index`中，如果房间`room[index]`中的所有钥匙不在`visited`当中，则将该钥匙对应房间号`room[index][i]`加入到队列中，等待被拜访
- 每访问完一间房间就将其`pop`掉，并使`entered[i]`加`1`，直到队列为空。
- 遍历`entered`中元素，若存在为`0`的元素,则说明有房间无法进入，返回`false`;反之返回`true`

代码如下：
```C++ []
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        if(rooms[0].empty()){
            if(rooms.size() == 1)
                return true;
            return false;
        } 
        queue<int> keys;
        vector<int> entered(rooms.size(), 0);
        unordered_set<int> visited;
        
        keys.push(0);
        
        while(!keys.empty()) {
            int index = keys.front();
            keys.pop();
            visited.insert(index);
            entered[index]++;
            
            for(int i = 0; i < rooms[index].size(); i++) {
                int next = rooms[index][i];
                if(visited.find(next) == visited.end()){
                    keys.push(next);
                }
            }
        }
        
        for(int i = 0; i < entered.size(); i++) {
            if(entered[i] == 0)
                return false;
        }
        return true;
    }
};
```

