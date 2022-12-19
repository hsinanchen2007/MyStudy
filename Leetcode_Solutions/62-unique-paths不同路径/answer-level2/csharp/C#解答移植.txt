# 递归做法
```csharp []
static int[,] a = new int[101, 101];
public int UniquePaths(int m, int n)//递归
{
    if (m == 1 || n == 1)
        return 1;
    if (m == 2)
        return n;
    else if (n == 2)
        return m;
    if (a[m, n] > 0)
        return a[m, n];
    a[m - 1, n] = UniquePaths(m - 1, n);
    a[m, n - 1] = UniquePaths(m, n - 1);
    a[m, n] = a[m - 1, n] + a[m, n - 1];
    return a[m, n];
}
```
# 动态规划
```csharp
public int UniquePaths(int m, int n)//动态规划
{
    int[] a = new int[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            a[j] += a[j - 1];
        }
    }
    return a[m - 1];
}
```
以上是对题解的c#移植，详细解答请看精选题解。

