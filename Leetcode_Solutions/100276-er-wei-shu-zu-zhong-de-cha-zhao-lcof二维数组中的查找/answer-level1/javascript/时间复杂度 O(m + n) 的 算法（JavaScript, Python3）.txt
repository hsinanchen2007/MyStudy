
## 思路

符合直觉的做法是两层循环遍历，时间复杂度是O(m * n), 
有没有时间复杂度更好的做法呢？ 答案是有，那就是充分运用矩阵的特性（横向纵向都递增），
我们可以从角落（左下或者右上）开始遍历，这样时间复杂度是O(m + n).

![](https://pic.leetcode-cn.com/c932820863157302000c9f4000c6730f9d749c15744317ba78b4dc763f92d32d.jpg)

其中蓝色代表我们选择的起点元素， 红色代表目标元素。

## 关键点解析

- 从角落开始遍历，利用递增的特性简化时间复杂度


## 代码

代码支持：JavaScript, Python3


JavaScript Code:

```js

/*
 * @lc app=leetcode id=240 lang=javascript
 *
 * [240] Search a 2D Matrix II
 *
 * https://leetcode.com/problems/search-a-2d-matrix-ii/description/
 *
 * 
 */
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    if (!matrix || matrix.length === 0) return 0;

    let colIndex = 0;
    let rowIndex = matrix.length - 1;
    while(rowIndex > 0 && target < matrix[rowIndex][colIndex]) {
        rowIndex --;
    }

    while(colIndex < matrix[0].length) {
        if (target === matrix[rowIndex][colIndex]) return true;
        if (target > matrix[rowIndex][colIndex]) {
            colIndex ++;
        } else if (rowIndex > 0){
            rowIndex --;
        } else {
            return false;
        }
    }

    return  false;
};
```

Python Code:

```python
class Solution:
    def findNumberIn2DArray(self, matrix, target):
        m = len(matrix)
        if m == 0:
            return False
        n = len(matrix[0])
        i = m - 1
        j = 0

        while i >= 0 and j < n:
            if matrix[i][j] == target:
                return True
            if matrix[i][j] > target:
                i -= 1
            else:
                j += 1
        return False
```

