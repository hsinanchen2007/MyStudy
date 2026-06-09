![微信截图_20200229170612.png](https://pic.leetcode-cn.com/7f6cc0305e3c19b8d0535043dab401fad1f70cded092ecf6c537210995467f84-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200229170612.png)


### 代码

```c
char *getPermutation(int n, int k)
{
    char *str = (char *)malloc(sizeof(char) * n + 1);
    str[n] = '\0';
    char mark[n];
    memset(mark, 0, sizeof(char) * n);
    int factorial = 1, i, j;
    for (i = 2; i < n; i++)
        factorial *= i;
    for (i = 0; i < n; i++)
    {
        for (j = 0; mark[j] || k > factorial; j++)
            if (!mark[j])
                k -= factorial;
        str[i] = '1' + j;
        mark[j] = 1;
        factorial /= (n - i - 1) == 0 ? 1 : n - i - 1;
    }
    return str;
}
```