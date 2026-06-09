一维前缀和
每行或者每列的从下标0 到下标i 元素之和
如 [1,2,3,4,5,6]  -> [1, 3, 6, 10, 15, 21]

二维前缀和
从（0，0）到（n, m）的元素之和
如
```javascript
[[1,2,3],                  [[1, 3, 6],
 [1,2,3],           =>     [2, 6, 12],
 [1,2,3]]		           [3, 9, 18]]
```
获得二元前缀和的方法
S(x, y) = S(x, y - 1) + S(x - 1, y) + item(x, y) - S(x - 1, y - 1)

(没东西画图 不知道怎么解释这个公式)
可以理解这个S(2, 2)
![image.png](https://pic.leetcode-cn.com/c2ea6aba475935bb3a0a2dc94ca36a4ddbaeab6da878875e68a8e6132fe7a55f-image.png)
它是由一个S(1,2)![image.png](https://pic.leetcode-cn.com/c48b4c39fc6839ee59475cd0867dd20fa48f29ffe04de5cc215f3beeea8c4db6-image.png)
以及一个S(2,1)![image.png](https://pic.leetcode-cn.com/03188b6a267f769e6be48733e013d964ad698fa9424f5d2b1ebf0a6f1a52e5e5-image.png)
再加上对应元素3组成，S(1,2) 和 S(2,1)重合部分 面积为 S(1,1)


当获得到二维前缀和的二维数组之后,我们就可以把这个问题理解成跟上面类似的图形面积问题了
``` javascript
/**
 * @param {number[][]} matrix
 */
var NumMatrix = function(matrix) {
    if (matrix.length === 0) {
        this.data = []
        return 
    }
    this.data = []
    for (let i = 0; i < matrix.length; i++) {
        this.data.push([0])
    }
    this.data.unshift(new Array(matrix[0].length + 1).fill(0))
    for(let i= 1; i < matrix.length + 1; i++) {
        for(let j= 1; j < matrix[0].length + 1; j++) {
            this.data[i][j] = this.data[i][j - 1] + this.data[i - 1][j] + matrix[i - 1][j - 1] - this.data[i - 1][j - 1]
        }
    }
};

/** 
 * @param {number} row1 
 * @param {number} col1 
 * @param {number} row2 
 * @param {number} col2
 * @return {number}
 */
NumMatrix.prototype.sumRegion = function(row1, col1, row2, col2) {
    if (this.data.length === 0) {
        return
    }
    return this.data[row2 + 1][col2 + 1] - this.data[row2 + 1][col1] - this.data[row1][col2 + 1] + this.data[row1][col1]
};
/** 
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
```