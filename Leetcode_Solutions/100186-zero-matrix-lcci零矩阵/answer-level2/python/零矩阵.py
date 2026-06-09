### 解题思路
1.
对于二阶矩阵，先将所有的0元素的行列读取到列表中，其中行的index为奇数，列的index为偶数
再将每一行和每一列对应的元素遍历为0

### 代码

```python3
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        nums = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == 0:
                    nums.append(i)
                    nums.append(j)
        for num in range(len(nums)):
            if num % 2 == 0:
                for j in range(len(matrix[0])):
                    matrix[nums[num]][j] = 0
            elif num % 2 == 1:
                for j in range(len(matrix)):
                    matrix[j][nums[num]] = 0

'''
作者：gggzyj
链接：https://leetcode-cn.com/problems/zero-matrix-lcci/solution/bai-fen-bai-nei-cun-by-gggzyj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
'''
```