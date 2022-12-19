### 解题思路
和168题类似，也是进制转换，不过这次是26进制转换为10进制
n进制s转换为10进制，累加第i位与n的乘积(即s[i]*n^i))

### 代码

```c
int titleToNumber(char * s)
{
    int r = 0;
    for (int i = 0; s[i]; ++i)
        r = r*26 + (s[i]-'A'+1);
    return r;
}
```