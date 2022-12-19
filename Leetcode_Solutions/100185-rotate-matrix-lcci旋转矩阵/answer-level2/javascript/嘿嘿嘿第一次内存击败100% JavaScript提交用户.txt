![微信截图_20200407215725.png](https://pic.leetcode-cn.com/d5a4c56ff7bda8c3fdfcf8d5ec5ee6436c3042438e6eab02d53cec0ad091cc23-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407215725.png)

/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    if (matrix.length > 1) {
        for (let i = 0; i < matrix.length; i++) {
            for (let j = 0; j < matrix.length; j++) {
                var temp = matrix[i].shift()
                matrix[j].push(temp)
            }
        }
        for (let i = 0; i < matrix.length; i++) {
            matrix[i] = matrix[i].reverse()
        }
    }
};