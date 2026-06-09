### 解题思路
细心一些就好了

### 代码

```c
char * multiply(char * num1, char * num2)
{
    int len1 = strlen(num1), len2 = strlen(num2);
    char* ans = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    memset(ans, '0', sizeof(char) * (len1 + len2));
    ans[len1 + len2] = '\0';
    int c = 0;
    for (int i = len2 - 1; i >= 0; i--)
    {
        int b = num2[i] - '0';
        for (int j = len1 - 1; j >= 0; j--)
        {
            int a = num1[j] - '0';
            int d = ans[i + j + 1] - '0';
            int x = a * b + d + c;
            ans[i + j + 1] = x % 10 + '0';
            c = x / 10;
        }
        if (c)
        {
            ans[i] = c + '0';
            c = 0;
        }
    }
    //下面去除前缀0
    int k = 0;
    for (; ans[k] == '0' && k <= len1 + len2; k++);
    if (k == len1 + len2) return "0";
    else ans += k;
    return ans;
}
```