### 解题思路
动态规划

### 代码

```c
int numTrees(int n){
    // Catalan number：f(n) =  f(0)f(n-1) + f(1)f(n-2) + ... + f(n-2)f(1) + f(n-1)f(0)

    int sum[n+1];
    memset(sum, 0, sizeof(sum));
    sum[0] = 1;
    int i, j;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= i; j++)
        {
            sum[i] += sum[j - 1] * sum[i - j];
        }
    }
    
    return sum[n];
}
```