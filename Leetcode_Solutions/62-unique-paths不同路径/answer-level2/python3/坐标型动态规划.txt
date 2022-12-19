这是一道入门级坐标型动态规划的题目，比较简单。
1. 对于机器人所到的某一个位置，它仅仅能从该位置的左边或者上边过来。对于图中的（2,3）位置机器人只能从（1,3）或者（2,2）处过来.
2. 那么现在令f(i,j)是机器人从（0,0）到达（i,j）的不同路径数，则f(i,j) = f(i-1,j)+f(i,j-1)，这里要注意边界条件i和i-1的范围是[0,m-1],j和j-1的范围是[0,n-1]。
3. 上面给出状态转移方程，初始条件f(0,0) = 1,从（0,0）位置到(0,0)位置只有一种走法
4. 时间复杂度O(M * N)，空间复杂度O(M * N)

![image.png](https://pic.leetcode-cn.com/0356dc54a079e0af7a91ab8dc6c26b818d3961d8ca6de3775d73de5b43c53d00-image.png)

## python3 代码
``` python
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        f = [[1]*n for x in range(m)]
        for i in range(m):
            for j in range(n):
                if(i == 0 or j == 0):
                    f[i][j] = 1
                else:
                    f[i][j] = f[i-1][j]+ f[i][j-1]
        return f[-1][-1]
```

# [原文链接](https://mp.weixin.qq.com/s?__biz=MzIxOTc1MDgyMw==&mid=2247483658&idx=1&sn=ba486f2f9d355a688cad6a78b61876fe&chksm=97d7c9c2a0a040d405e4b758e972269ea2d750682e4075389bff5be8799a708d134e3a276eb9&token=664162831&lang=zh_CN#rd)