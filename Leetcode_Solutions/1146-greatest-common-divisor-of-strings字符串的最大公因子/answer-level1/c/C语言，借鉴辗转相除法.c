**解题思路** 如果两个字符串之间存在最大公因子：
    （1） 短串一定是和在长串的前strlen(短串)字符组成的子串相同；
    （2） 长串不断减去短串，得到的两个字符串（原有短串和差串）同样满足(1)中关系；
    （3） 当等到的两个串相同时，即为最大公因子。

![leetcode1071.png](https://pic.leetcode-cn.com/ad6c0f093e0f0c676f8fdb1306555901468033c8c2e634c1bfbaf439c4474618-leetcode1071.png)

例：ABABAB,AB

    (1) AB和ABABAB[0-1]相同，ABABAB-ABABAB[0-1]，得到ABAB
    (2) AB和ABAB[0-1]相同，ABAB-ABAB[0-1],得到AB
    (3) AB和AB相同，得到最大公因子为AB


```
char * gcdOfStrings(char * str1, char * str2){
    char *lger = strlen(str1) > strlen(str2) ? str1 : str2;
    char *sher = strlen(str1) > strlen(str2) ? str2 : str1;

    if (strcmp(lger, sher) == 0) {
        return sher;
    }

    if (strncmp(lger, sher, strlen(sher)) != 0) {
        return "";
    } 

    return gcdOfStrings(lger + strlen(sher), sher);
}
```

可能因为是递归方式，耗时比较久。