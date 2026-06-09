### 解题思路
转化为邻接矩阵，遇见出度为0的人，就判断他的入度，如果入度为N-1,返回此人；否则继续，直到遍历结束。
### 代码

```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        mat=[[0]*N for i in range(N)]
        for t in trust:
            mat[t[0]-1][t[1]-1]=1
        for i in range(N):
            if sum(mat[i])==0:
                tmp=0
                for j in range(N):
                    tmp+=mat[j][i]
                if tmp==N-1:
                    return i+1
        return -1
```