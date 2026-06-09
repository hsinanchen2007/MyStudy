### 解题思路
![image.png](https://pic.leetcode-cn.com/d9d03dc08ad018bfbe3539eb400adf0c9f62aec3dce32e0723994691270455b2-image.png)

用一个js的set来放已经进入过的房间号，如果当前的钥匙串都已经进过了，就结束循环，比较set和rooms的大小是否相等。

### 代码

```javascript
/**
 * @param {number[][]} rooms
 * @return {boolean}
 */
var canVisitAllRooms = function (rooms) {
    if (!rooms[0].length) {
        if (rooms.length === 1) return true;
        return false;
    }
    let visited = new Set();
    let que = [rooms[0]];
    let allVisited = true;

    visited.add(0);

    while (que.length) {
        let len = que.length;
        allVisited = true;
        for (let i = 0; i < len; i++) {
            let keyListofCurrRoom = que.shift();
            keyListofCurrRoom.forEach(roomKey => {
                que.push(rooms[roomKey]);
                if (!visited.has(roomKey)) {
                    visited.add(roomKey);
                    allVisited = false;
                }
            })
        }
        if (allVisited) break;
    }
    return visited.size === rooms.length;
};
```