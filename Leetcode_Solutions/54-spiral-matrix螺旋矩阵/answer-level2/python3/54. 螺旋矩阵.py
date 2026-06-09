### 解题思路
这道题顺着题意求解就行，可以视作沿着指定轨迹行走的过程，只不过要注意这里有墙，边界与以访问过的元素就是墙，撞墙后要转向。

### 代码

```python3
class Solution:
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        m = len(matrix)
        n = len(matrix[0])
        seen = []
        for i in range(m):
            seen.append([False]*n)
        count = i = j = 0
        res = []
        while count<m*n:
            # 向右
            while -1<i<m and -1<j<n and not seen[i][j]: #撞墙了就结束
                res.append(matrix[i][j])
                seen[i][j]=True
                j+=1
                count+=1
            j-=1
            i+=1
            # 向下
            while -1<i<m and -1<j<n and not seen[i][j]:
                res.append(matrix[i][j])
                seen[i][j]=True
                i+=1
                count+=1
            i-=1
            j-=1
            # 向左
            while -1<i<m and -1<j<n and not seen[i][j]:
                res.append(matrix[i][j])
                seen[i][j]=True
                j-=1
                count+=1
            j+=1
            i-=1
            # 向上
            while -1<i<m and -1<j<n and not seen[i][j]:
                res.append(matrix[i][j])
                seen[i][j]=True
                i-=1
                count+=1
            i+=1
            j+=1
        return res
```