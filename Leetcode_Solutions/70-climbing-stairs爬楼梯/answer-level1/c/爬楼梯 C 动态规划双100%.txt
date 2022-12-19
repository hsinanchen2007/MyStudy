### 解题思路
一开始用递归超时，这道题展示了动态规划就像逆向的递归，因为可以保存上次的结果，故而可提高效率。

### 代码

```c
int climbStairs(int n){
    int *plan = NULL;
    int i;

    if (n == 1) {
        return 1;
    }

    plan = (int *)malloc(sizeof(int) * (n + 1));

    plan[1] = 1;
    plan[2] = 2;

    for (i = 3; i <= n; i++) {
        plan[i] = plan[i - 1] + plan[i - 2];
    }
    return plan[n];
} 
```