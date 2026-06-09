![QQ截图20190808085723.png](https://pic.leetcode-cn.com/ab1247f364d94f866fa7f976247901d1e4d0dff398d6bd0d175b693ed8b4a758-QQ%E6%88%AA%E5%9B%BE20190808085723.png)
由于0和1是分别组合在一起的，也就是说满足要求的字符串（不会存在0和1混合的情况如：0101  1001）
```
int countBinarySubstrings(char * s){
    int n = 0, pre = 0, curr = 1, len = strlen(s)-1;
    for (int i = 0; i < len; ++i) {
        if (s[i] == s[i+1]) ++curr;
        else               {pre = curr; curr = 1;}
        if (pre >= curr) ++n;
    }
    return n;
}
```
