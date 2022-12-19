![QQ截图20190719073000.png](https://pic.leetcode-cn.com/6810d2c61eb48ea8b3a6a0f787c8f24f61d7d5ebdfbc2c940a540ab5234c8220-QQ%E6%88%AA%E5%9B%BE20190719073000.png)

```
char * customSortString(char * S, char * T){
    if (S == NULL || T == NULL) return NULL;
    int value[128];
    for (int i = 'a'; i < 'z'+1; ++i) value[i] = 0;
    char *ret_str = (char *)malloc(1024);
    if (ret_str == NULL) return NULL;              //上面为初始化
    
    for (int i = 0; T[i]; ++i) ++value[T[i]];//记录字符串中每个字符的个数
    int fir = 0;
    for (int i = 0; S[i]; ++i) {
        while (value[S[i]]) {     //判断S中的字符是否在T中也有，注意T中有重复字符
            ret_str[fir++] = S[i];
            --value[S[i]];
        }
    }
    for (int i = 'a'; i < 'z'+1; ++i) {  //剩下的字符
        while (value[i]) {
            ret_str[fir++] = i;
            --value[i];
        }
    }
    ret_str[fir] = '\0';
    return ret_str;
}
```
