### 解题思路
此处撰写解题思路
![图片.png](https://pic.leetcode-cn.com/37342460e6c143e1ccf2c65d8462dfddaf5b5fdb7850eb6c76313c8e52f4052e-%E5%9B%BE%E7%89%87.png)
### 代码

```python3
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        for i in range(len(matrix)):
            if not matrix[i]:
                matrix.pop(i)
        # print(matrix)
        if not matrix: return False
        if len(matrix[0]) ==1:
            for i in range(len(matrix)):
                if matrix[i][0] == target:
                    return True
            return False
        n = len(matrix)
        m = len(matrix[0])
        if matrix[n-1][m-1] < target: return False
        if matrix[0][0] > target: return False

        end = m-1
        # 先找到target 在哪一行
        for start in range(0, n):
            if matrix[start][end] >= target:
                break
        i, j = 0, end
        while i <= j:
            if matrix[start][i]==target or matrix[start][j] == target:
                return True
            elif matrix[start][i] < target:
                i+=1
            elif matrix[start][j] > target:
                j-=1
        return False


        


```