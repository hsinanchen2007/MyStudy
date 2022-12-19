### 解题思路
方法一：动态规划算法
1,找到 f(n)、f(n-1)、f(n-2)之间的关系，
2,得到  f(n)=f(n-1)+f(n-2)
3,使用 dp[n]保存每阶楼梯的方法数
4,空间优化使用2个变量保存中间值即可

### 代码

```c
//方法一：动态规划算法
//1,找到 f(n)、f(n-1)、f(n-2)之间的关系，
//2,得到  f(n)=f(n-1)+f(n-2)
//3,使用 dp[n]保存每阶楼梯的方法数
//4,空间优化使用2个变量保存中间值即可
int climbStairs(int n){
    int     i       = 0;
    int     iTmp_1  = 1;
    int     iTmp_2  = 2;
    int     iRet    = 0;

    if (1 == n) return iTmp_1;
    if (2 == n) return iTmp_2;

    for (i = 3; i <= n; i++)
    {
        iRet = iTmp_1 + iTmp_2;
        iTmp_1 = iTmp_2;
        iTmp_2 = iRet;
    }

    return iRet;
}
```