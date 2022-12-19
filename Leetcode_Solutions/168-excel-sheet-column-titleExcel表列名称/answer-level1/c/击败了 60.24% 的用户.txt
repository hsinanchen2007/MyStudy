### 解题思路
十进制转26进制

### 代码

```c
char * convertToTitle(int n){
    int x, i = 0, j, temp;
    static char str[64];

    do
    {
        n--;
        x = n % 26;
        str[i++] = x + 'A';
        n /= 26;
    } while (0 != n);
    for (j = 0; j < i / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
    str[i] = '\0';
    return str;
}
```