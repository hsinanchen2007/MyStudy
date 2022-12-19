### 解题思路
下面的代码复杂度为O(MN)，空间负责度为O(M).主要有两个状态变量，pre代表上一层的最小路径和，cur代表当前这层的最小路径和。

### 代码

```python3
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle or not triangle[0]:
            return 0
        rows = len(triangle)
        pre = [0]*rows
        cur = [0]*rows
        pre[0]=triangle[0][0]
        for i in range(1,rows):
            for j in range(len(triangle[i])):
                if j==0:
                    cur[j] = pre[j]+triangle[i][j]
                elif j==len(triangle[i])-1:
                    cur[j] = pre[j-1]+triangle[i][j]
                else:
                    cur[j] = min(pre[j],pre[j-1])+triangle[i][j]
            for k in range(rows):
                pre[k] = cur[k]
        return min(pre)


```