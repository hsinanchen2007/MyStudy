### 解题思路
对于一个坐标能不能被到达，取决于两点（1）是否满足基本条件行坐标和列坐标的数位之和不大于k（2）能否与[0,0]形成通路
如果坐标[i,j]的左右上下能被到达且满足条件（1），则[i,j]能被到达。
代码实现：
_true函数生成是否满足条件（1）的label(m x n),用d(m x n)来存储各个坐标能否被到达，不断对d进行判断修改，直到d不在改变，最后sum([sum(x) for x in d])就是满足条件（1）（2）的坐标数

### 代码

```python3
class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        def _true(i,j,k):
            i1=i//100
            i2=i//10-i1*10
            i3=i-i1*100-i2*10
            j1=j//100
            j2=j//10-j1*10
            j3=j-j1*100-j2*10
            if i1+i2+i3+j1+j2+j3<=k:
                return True
            else:
                return False
        label=[[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if _true(i,j,k):
                    label[i][j]=1
        d=[[0]*n for _ in range(m)]
        d[0][0]=1
        flag=1
        while flag:
            flag=0
            for i in range(m):
                for j in range(n):
                    if d[i][j]==0 and label[i][j]==1:
                        if (j-1>=0 and d[i][j-1]==1) or (j+1<n and d[i][j+1]==1) or (i-1>=0 and d[i-1][j]==1) or (i+1<m and d[i+1][j]==1):
                            d[i][j]=1
                            flag=1
        return sum([sum(x) for x in d])








```