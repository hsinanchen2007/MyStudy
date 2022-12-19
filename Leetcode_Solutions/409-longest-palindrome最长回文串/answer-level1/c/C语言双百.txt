### 解题思路
定义一维数组存入每个字符出现次数，数其中出现奇数次的个数即可。

### 代码

```c
int longestPalindrome(char * s){
    int i, len=strlen(s), count=0;
    char cs[58];
    for(i=0; i<58; i++)
        cs[i] = 0;
    for(i=0; i<len; i++)
        cs[s[i]-65]++;
    for(i=0; i<58; i++){
        if(cs[i] == 0)
            continue;
        if(cs[i]%2 != 0)
            count++;
    }
    if(count > 0)
        return len-count+1;
    return len;
}
```