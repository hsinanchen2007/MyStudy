
![QQ截图20190720084626.png](https://pic.leetcode-cn.com/4da2362b4675d5b6a5e7e48c18a3dfa460ebcb827011b7f4d1dc537ddbcd309a-QQ%E6%88%AA%E5%9B%BE20190720084626.png)

```
char binary_str[1024];
bool queryString(char * S, int N){
    if (S == NULL || S[0] == '\0') return false;
    for (int i = 1; i <= N; ++i) {
        binary_conversion(i);
        if (strstr(S, binary_str) == NULL) return false;  //判断是否为子串
    }
    return true;
}
void binary_conversion(int value) //转换为二进制字符串
{
    int i = 0;
    while (value) {
        binary_str[i++] = (1 & value) + '0';
        value >>= 1;
    }
    binary_str[i--] = '\0';
    for (int j = 0; j < i; ++j, --i) {
        binary_str[j] ^= binary_str[i] ^= binary_str[j] ^= binary_str[i];
    }
}
```
