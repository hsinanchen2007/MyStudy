### 解题思路

seat_map 用一个整数表示一行的状态

line_state 标识任意一行所有可行的座位安排（其实就是没有相邻的）因为单就一行来看，只要没人相邻就 ok

line_state 中任意一个和 seat_map 的任意一行做按位与，看是否变化，就可以知道这一行是否可以这么座（是否会坐到坏座位）

两行之间的是否合法，就是一行右移、左移再和另一行按位与。

本思路参考了排行榜上 leoGW 的代码，思路一致，但是重写了。

### 代码

```python
class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        n = len(seats)
        m = len(seats[0])
        dp = [[-1] *(1<<m) for i in range(n)]
        seat_map = [0] * n # 每个整数代表一行的座位，整数每个二进制位为 0 代表座位不能用， 1 代表能用
        for i, l in enumerate(seats):
            for ch in l:
                if ch == ".":
                    seat_map[i] = (seat_map[i] << 1) + 1 # 1 代表当前座位可用
                else:
                    seat_map[i] = (seat_map[i] << 1) + 0 # 0 代表当前座位不可用
        line_state = []
        num = []
        for i in range(1<<m):
            x = 3 # 3 的二进制是 011，表示有两个座位挨着的情况
            f = True
            for j in range(m):
                if i & x == x: # 有相邻座位
                    f = False
                    break
                x <<= 1
            if not f: continue
            line_state.append(i)
            num.append(str(bin(i)).count('1'))
            if i & seat_map[0] == i:
                dp[0][i] = num[-1]
        print(line_state)
        print(num)
        for i in range(1, n):
            for j, jn in zip(line_state, num):
                if j & seat_map[i] == j:
                    for k in line_state:
                        if ((j << 1) & k ==0 ) and ((j >> 1) & k == 0): # 两行没有斜对角的人
                            dp[i][j] = max(dp[i-1][k] + jn, dp[i][j])
        return max(dp[n-1])
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)