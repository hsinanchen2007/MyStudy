## 解法 1：暴力法

遍历数组中的所有元素，找到是否存在。

时间复杂度是 O(N^2)，空间复杂度是 O(1)

```javascript
// ac地址：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/submissions/
// 原文地址：https://xxoo521.com/2019-12-19-er-wei-shu-zu-cha-zhao/

/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    const rowNum = matrix.length;
    if (!rowNum) {
        return false;
    }
    const colNum = matrix[0].length;
    for (let i = 0; i < rowNum; i++) {
        for (let j = 0; j < colNum; j++) {
            if (matrix[i][j] === target) return true;
        }
    }

    return false;
};
```

## 解法 2：观察数组规律

按照题目要求，数组的特点是：**每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序**。考虑以下数组：

```
1 2 3
4 5 6
7 8 9
```

在其中寻找 5 是否存在。过程如下：

1. 从右上角开始遍历
2. 当前元素小于目标元素(3 < 5)，根据数组特点，当前行中最大元素也小于目标元素，因此进入下一行
3. 当前元素大于目标元素(6 > 5)，根据数组特点，行数不变，尝试向前一列查找
4. 找到 5

代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
// 原文地址：https://xxoo521.com/2019-12-19-er-wei-shu-zu-cha-zhao/
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    const rowNum = matrix.length;
    if (!rowNum) {
        return false;
    }
    const colNum = matrix[0].length;
    if (!colNum) {
        return false;
    }

    let row = 0,
        col = colNum - 1;
    while (row < rowNum && col >= 0) {
        if (matrix[row][col] === target) {
            return true;
        } else if (matrix[row][col] > target) {
            --col;
        } else {
            ++row;
        }
    }

    return false;
};

```

时间复杂度是 O(M+N)，空间复杂度是 O(1)。其中 M 和 N 分别代表行数和列数。

---

> **📖Blog：[剑指 Offer 题解 + JS 代码](https://xxoo521.com/algorithm/)**
> **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
> **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**

