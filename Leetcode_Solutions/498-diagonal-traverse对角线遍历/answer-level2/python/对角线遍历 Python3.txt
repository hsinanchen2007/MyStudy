### 解题思路
执行用时 :220 ms, 在所有 Python3 提交中击败了77.91%的用户
内存消耗 :16.3 MB, 在所有 Python3 提交中击败了5.09%的用户

思路：
找规律。。。
1. 计算每个斜线的数字个数，例如一个3行5列的矩阵，斜线的数字个数为[1,2,3,3,3,3,2,1]
2. 第索引是偶数的斜线的打印方向是“右上↗”，奇数的是“左下↙”
3. 下一个打印方向是“左下”的斜线中，如果是右侧有数字的情况，是“右->一直左下”；如果是右侧没有数字的情况，则是“下->一直左下”
4. 下一个打印方向是“右上”的斜线中，如果是下面有数字的情况，是“下->一直右上”；如果是下面没有数字的情况，则是“右->一直右上”
### 代码

```python3
class Solution:
    def findDiagonalOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])
        
        lens = []
        mn = sorted([m, n])
        
        for i in range(mn[0]-1):
            lens.append(i+1)
        for i in range(mn[1]-mn[0]+1):
            lens.append(mn[0])
        for i in range(mn[0]-1):
            lens.append(mn[0]-1-i)
        
        res = []
        i = -1
        j = 0
        for t, k in enumerate(lens):
            if t % 2 == 0:
                # 右上
                if i < m-1:
                    i += 1
                else:
                    j += 1
                res.append(matrix[i][j])
                for _ in range(k-1):
                    i -= 1
                    j += 1
                    res.append(matrix[i][j])
            else:
                # 左下
                if j < n - 1:
                    j += 1
                else:
                    i += 1
                res.append(matrix[i][j])
                for _ in range(k-1):
                    i += 1
                    j -= 1
                    res.append(matrix[i][j])
                    
        return res
        
```