### 解题思路
![image.png](https://pic.leetcode-cn.com/585a7fcdac0c1d6291a53e82f949130c3dad46320a03a5b17ebc2157939b7a24-image.png)

数据量不大，还是创建了一个二维数组比较直观，1表示能到，0表示不能到，-1表示“已检查”。

### 代码

```javascript
const digSum = num => {
    if (num / 10 < 1) return num;
    let sum = 0;
    while (num != 0) {
        sum += num % 10;
        num = (num - num % 10) / 10;
    }
    return sum;
}

/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function (m, n, k) {
    if (k === 0) return 1;
    let step = 1;
    let matrix = [];
    let que = [];
    for (let i = 0; i < m; i++) {
        let row = [];
        for (let j = 0; j < n; j++) {
            if (digSum(i) + digSum(j) <= k) {
                row.push(1);
            } else {
                row.push(0);
            }
        }
        matrix.push(row);
    }
    que.push([0, 0]);
    matrix[0][0] = -1;

    while (que.length) {
        const len = que.length;
        for (let i = 0; i < len; i++) {
            const curr = que.shift();
            const x = curr[0];
            const y = curr[1];

            // only need check directions of Right and Down
            if (x < m - 1 && matrix[x + 1][y] > 0) {
                que.push([x + 1, y]);
                matrix[x + 1][y] = -1;
                step++;
            }
            if (y < n - 1 && matrix[x][y + 1] > 0) {
                que.push([x, y + 1]);
                matrix[x][y + 1] = 0;
                step++;
            }
        }
    }
    return step;
};
```