### 解题思路
同习题 [面试题04. 二维数组中的查找](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)
对角线解法，简单易懂。 T(n+m)

也可采用分治法。 T(n)= 3T(1/4 n) + O(n)  见题解 [gelthin-分治递归-小技巧](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/solution/di-gui-fang-fa-by-gelthin/)

### 代码

```python3
class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        m = len(matrix)
        if m==0:
            return False
        n = len(matrix[0])
        i, j = 0, n-1
        while (i<=m-1) and (j>=0):
            if matrix[i][j] == target:
                return True
            elif matrix[i][j] > target:
                j -= 1
            else:
                i += 1
        return False
```