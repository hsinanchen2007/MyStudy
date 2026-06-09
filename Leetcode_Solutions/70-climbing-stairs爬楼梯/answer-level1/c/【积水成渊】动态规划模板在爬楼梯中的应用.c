### 解题思路
使用动态规划的思路
1 问题分解
每一步的最优解，构成整体的最优解；
2 状态定义
1）当前所在的位置--i
2）当前位置的最小路径--method[i]
3 转移方程推导
method[i] = method[i - 1] + method[i - 2]
4 边界条件
0)当n=0时，直接返回零；
1）method[0] = 1;method[1]=1;
2)i的取值范围[2,n];


### 代码

```c
int climbStairs(int n){
    int *method = (int *)malloc((n + 1) * sizeof(int));
    int i;

    if (n == 0) {
        return 0;
    }
    method[0] = 1;
    method[1] = 1;
    for (i = 2; i <= n; i++) {
        method[i] = method[i - 1] + method[i - 2];
    }
    return method[n];
}
```