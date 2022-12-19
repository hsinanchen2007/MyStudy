[点我查看原题](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)  
[点我查看原文](https://juejin.im/post/5e54d3c3f265da5756325410)

## 题目描述

在一个 $n * m$ 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

## 解题思路  

- 暴力写法：
    1. 直接遍历，从头开始找直到匹配目标值；
    2. 从左上角开始递归，如果当前值 **小于** 目标值，那么往 **右边 / 下边** 走，直到匹配目标值。

- 巧妙写法：
    1. 从右上角开始递归，如果当前值 **小于** 目标值，那么往 **下边** 走，如果当前值 **大于** 目标值，那么往 **左边** 走；
    2. 从右上角开始循环，逻辑同上。

## 示例代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    const helper = (x, y) => {
        if (x === height || y < 0) {
            return false
        }
        if (matrix[x][y] === target) {
            return true
        }
        // 如果当前值小于目标值，那么往下边走
        if (matrix[x][y] < target) {
            return helper(x + 1, y)
        }
        // 否则往左边走
        return helper(x, y - 1)
    }
    if (!matrix.length) {
        return false
    }
    let width = matrix[0].length
    let height = matrix.length
    return helper(0, width - 1)
};
```