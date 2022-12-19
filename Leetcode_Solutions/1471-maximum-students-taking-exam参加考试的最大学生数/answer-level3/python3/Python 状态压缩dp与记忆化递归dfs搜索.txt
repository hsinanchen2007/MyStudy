### 解题思路

借鉴自
[fanhua--java压缩dp与记忆化递归](https://leetcode-cn.com/problems/maximum-students-taking-exam/solution/dpjava-by-henrylee4/)
但两种不同实现方式在中并没有体现出速度的差距，可能是因为函数递归调用开销比较大？？。具体的不是很了解。

### 代码
压缩状态dp 80ms
```python3 []
from functools import reduce
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        memo=dict()
        r,c=len(seats),len(seats[0])
        row=[j for j in range(1<<c) if not j&j<<1 and not j&j>>1]
        dp=[[0]*(1<<c) for _ in range(r+1)]
        rows=[255]+[reduce(lambda x,y:x|1<<y , [0]+[j for j in range(c) if seats[i][j]=='#'  ]) for i in range(r)]
        for i in range(1,r+1):
            for j in row:
                if not j&j<<1 and not j&j>>1 and not j&rows[i]:#j可以坐人
                    for k in row:
                        if not j&k<<1 and not j&k>>1:
                            dp[i][j]=max(dp[i][j],dp[i-1][k]+bin(j).count('1'))
        return max(dp[-1])
```




记忆化递归 72ms
```python3
from functools import reduce
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        def dfs(memo,pre,index):
            if index==r:
                return 0
            if (pre,index) in memo:
                return memo[(pre,index)]
            res=0
            for j in row:
                if not j&rows[index] and not j&pre>>1 and not j&pre<<1:
                    res=max(res,bin(j).count('1')+dfs(memo,j,index+1))
            memo[(pre,index)]=res
            return res
        memo=dict()
        r,c=len(seats),len(seats[0])
        row=[j for j in range(1<<c) if not j&j<<1 and not j&j>>1]
        rows=[reduce(lambda x,y:x|1<<y , [0]+[j for j in range(c) if seats[i][j]=='#']) for i in range(r)]
        return dfs(memo,0,0)
    
```
