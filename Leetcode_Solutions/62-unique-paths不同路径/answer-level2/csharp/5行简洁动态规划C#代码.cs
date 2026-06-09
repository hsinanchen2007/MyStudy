# 解释
仅仅是简化了代码，本质上还是题解的一维数组存储的动态规划。
参考了国际站的C#代码。

# 代码
```
public int UniquePaths(int m, int n)
{
    int[] array = new int[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[j] = j == 0 ? 1 : array[j] + array[j - 1];
    return array[n - 1];
}
```
