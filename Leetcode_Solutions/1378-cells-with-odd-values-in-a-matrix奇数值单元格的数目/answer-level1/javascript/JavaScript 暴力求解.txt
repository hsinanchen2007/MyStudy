### 解题思路

![image.png](https://pic.leetcode-cn.com/5fef8f18d951cab6731ef538eaf168bac9a859f2bd9b112b39b85bf7ec7021e3-image.png)
- 通过 new Array 得到行列数，将题目中的二维数组进行拆分，单独成为一维数组
- 通过拆分，降低计算量。

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function(n, m, indices) {
    let rows = new Array(n).fill(0)
    let cols = new Array(m).fill(0)
    for(let i = 0;i < indices.length; i++){
        let rowIndex = indices[i][0]
        let colIndex = indices[i][1]
        rows[rowIndex]++
        cols[colIndex]++
    }
    let count = 0
    for(let i = 0; i < n; i++){
        for(let j = 0; j < m; j++){
            if((rows[i] + cols[j]) % 2 != 0){
                count++
            }
        }
    }
    return count
};
```