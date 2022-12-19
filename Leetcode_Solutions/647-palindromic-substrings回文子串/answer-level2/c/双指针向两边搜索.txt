解题思路和第5题类似，选定一个位置(分奇数和偶数情况)，向两边搜索，每次两个字符相等，则结果加1即可。

```C
int countSubstrings(char * s){
    int len = strlen(s);
    int res = 0;
    for(int i = 0; i < len; i++) {
        int r = i, l = i;
        while(r < len && l >= 0 && s[l] == s[r]) {
            l--;
            r++;
            res++;
        }
        l = i;
        r = i + 1;
        while(r < len && l >= 0 && s[l] == s[r]) {
            l--;
            r++;
            res++;
        } 
    }
    return res;
}
```