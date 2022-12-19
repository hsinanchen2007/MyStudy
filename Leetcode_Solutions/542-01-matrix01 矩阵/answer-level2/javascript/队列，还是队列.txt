### 解题思路
![image.png](https://pic.leetcode-cn.com/1ac26837b19106d9cfe05da21be03abece411610f06e1be2423a6d673773bcca-image.png)

典型队列应用场景，另外用一个map存放{距离，该距离的坐标数组}。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[][]}
 */
var updateMatrix = function(matrix) {
    const height = matrix.length;
    const width = matrix[0].length;
    let m = new Map();
    let que = [];
    let dist = 1;

    matrix.forEach((row, i) => {
        row.forEach((val, j) => {
            if (val === 0) {
                que.push([i, j]);
            }
        })
    })

    while (que.length) {
        let len = que.length;
        let arr = [];
        for (let i = 0; i < len; i++) {
            const pos = que.shift();
            const x = pos[0];
            const y = pos[1];
            if (x > 0 && matrix[x - 1][y] > 0) {
                que.push([x - 1, y]);
                arr.push([x - 1, y]);
                matrix[x - 1][y] = -1;
            }
            if (x < height - 1 && matrix[x + 1][y] > 0) {
                que.push([x + 1, y]);
                arr.push([x + 1, y]);
                matrix[x + 1][y] = -1;
            }
            if (y > 0 && matrix[x][y - 1] > 0) {
                que.push([x, y - 1]);
                arr.push([x, y - 1]);
                matrix[x][y - 1] = -1;
            }
            if (y < width - 1 && matrix[x][y + 1] > 0) {
                que.push([x, y + 1]);
                arr.push([x, y + 1]);
                matrix[x][y + 1] = 0;
            }
        }
        if (arr.length) {
            m.set(dist, arr);
        }
        dist++;
    }
    if (m.size) {
        for (let [key, posArr] of m) {
            posArr.forEach(pos => {
                matrix[pos[0]][pos[1]] = key;
            })
        }
    }
    return matrix;
};
```