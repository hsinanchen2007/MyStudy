### 解题思路
执行用时 :40 ms, 在所有 Python3 提交中击败了44.06%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了6.28%的用户

思路：
while循环，每次用one_circle(self, matrix)按照右、下、左、上的顺序算最外围一圈，然后扒掉最外围一圈

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        
        def one_circle(x, y, m ,n):
            res = []
            for i in range(n):
                res.append(matrix[x][y+i])
            for i in range(m-2):
                res.append(matrix[x+i+1][y+n-1])
            if m > 1:
                for i in range(n):
                    res.append(matrix[x+m-1][y+n-1-i])
            if n > 1:
                for i in range(m-2):
                    res.append(matrix[x+m-2-i][y])
            return res
        
        res = []
        m = len(matrix)
        n = len(matrix[0])
        p = 0
        while m > 0 and n > 0:
            res += one_circle(p, p, m, n)
            m -= 2
            n -= 2
            p += 1
            
        return res      
```