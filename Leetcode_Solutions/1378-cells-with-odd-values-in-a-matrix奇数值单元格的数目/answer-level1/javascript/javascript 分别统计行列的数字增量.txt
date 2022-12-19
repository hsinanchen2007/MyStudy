### 解题思路
两个数组分别统计行列增量，最后相加确认单元格奇偶
![leetcode1252.jpg](https://pic.leetcode-cn.com/a66a72d61882a246a6c2a9b0eb3d1c8d5899731b4a625e3536ed1b10e748f119-leetcode1252.jpg)

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function(n, m, indices) {
    // 存储每一行最终的增量
    const rows = new Array(n).fill(0)
    // 存储每一列最终的增量
    const cols = new Array(m).fill(0)
    const len = indices.length
    for (let i = 0; i < len; i++) {
        // 需要加1的行号
        const rowIndex = indices[i][0]
        // 需要加1的列号
        const colIndex = indices[i][1]
        rows[rowIndex] += 1
        cols[colIndex] += 1
    }
    // 存储奇数单元格数量
    let count = 0
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            // 如果单元格数字为奇数
            if ((rows[i] + cols[j]) % 2) {
                count ++
            }
        }
    }
    return count
};
```