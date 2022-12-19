### 解题思路
动态规划：画网格解决（行列为2个条件，路径和为其问题）
发现：由于只能向右/下走，故到达第一行/列的路径只有一条。
网格初始化为：（以3行4列为例）
- A B C D E
a 1 1 1 1 1
b 1 0 0 0 0
c 1 0 0 0 0
从1行1列向右下搜索，发现状态转移方程为'状态转移方程：`x[i][j]=x[i][j-1]+x[i-1][j], s.t. i in {A,B,C,D,E},j in {a,b,c}'
### 代码

```python3
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        #动态规划#
        #初始化：a[0][j]=1,a[i][0]=1
        #状态转移方程：a[i][j]=a[i][j-1]+a[i-1][j]
        arr0=[1]*n
        arr=[arr0]+[[1]+[0]*(n-1)]*(m-1)
        #状态求解
        for i in range(1,m):
            for j in range(1,n):
                arr[i][j]=arr[i-1][j]+arr[i][j-1]
        return arr[-1][-1]
            



```