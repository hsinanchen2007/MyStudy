### 解题思路
DFS，非常的直接，非常的效率低……

### 代码

```javascript
/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function(rooms) {

    var hasChecked = []; //已经检查过的房间
    var roomsChecked = 0; //检查的房间数量
    var checkSeq = [0]; //还需要检查的房间

        //你们JavaScript有一点好……就是不用担心ConcurrentModificationException
        for(var x of checkSeq){
            if(!hasChecked.includes(x)){
                roomsChecked += 1;
                hasChecked.push(x);
                for(var key of rooms[x]){
                    if(!hasChecked.includes(key)){
                        checkSeq.push(key);
                    }

                }
                
            }
        }

    return roomsChecked === rooms.length;

};
```