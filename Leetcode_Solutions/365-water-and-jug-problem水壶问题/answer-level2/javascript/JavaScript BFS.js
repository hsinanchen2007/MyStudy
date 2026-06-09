### 解题思路
    分析题意可用BFS求解

### 代码


```javascript
/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {boolean}
 */
// 整理逻辑情况 把可操作逻辑理清
//
//1、把X装满
//2、把Y装满
//3、把X排空
//4、把Y排空
//5、把X倒入Y   X有剩余 且Y满   X无剩余  Y满 或者 Y不瞒
//6、把Y倒入X   Y有剩余 且X满   Y无剩余  X满 或者 X不瞒
//三种情况 遍历所有可选情况   BFS
//1、模拟栈
var canMeasureWater = function (x, y, z) {
    if (z === 0) return true;
    let queue = [[0, 0]];
    // 记录访问过的数据;
    let visited = new Set();
    function bfs(x_remind, y_remind) {
        while (queue.length) {
            let size = queue.length;
            let array = [];
            while (size--) {
                let currentStatus = queue.shift();
                if (currentStatus[0] + currentStatus[1] === z || currentStatus[0] === z || currentStatus[1] === z)
                    return true;

                if (visited.has(currentStatus + '')) continue;
                visited.add(currentStatus + '');
                // X装满
                array.push([x, currentStatus[1]]);
                // Y装满
                array.push([currentStatus[0], y]);
                // X排空
                array.push([0, currentStatus[1]]);
                // Y排空
                array.push([currentStatus[0], 0]);
                // X倒入Y
                array.push([currentStatus[0] - Math.min((y - currentStatus[1]), currentStatus[0]), currentStatus[1] + Math.min((y - currentStatus[1]), currentStatus[0])]);
                // Y倒入X
                array.push([currentStatus[0] + Math.min((x - currentStatus[0]), currentStatus[1]), currentStatus[1] - Math.min((x - currentStatus[0]), currentStatus[1])]);
            }
            queue = array.slice(0);
        }
        return false;
    }
    return bfs(0, 0);
};
```