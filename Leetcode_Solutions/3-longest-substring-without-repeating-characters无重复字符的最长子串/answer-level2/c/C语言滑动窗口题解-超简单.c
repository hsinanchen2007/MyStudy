思路：建立一个hash统计当前窗口内的字符的数量，当窗口右侧拓展时对应字符数量增加，当窗口左侧收缩时对应字符数量减少

```
#define MAX_CHAR 256
int Max(int a, int b)
{
    return a > b ? a : b;
}
int lengthOfLongestSubstring(char * s){
    
    int hash[MAX_CHAR] = {0};
    
    int maxLen = 0;
    int l = 0;
    for (int r = 0; r < strlen(s); r++) {
        
        hash[s[r]]++;
        while (l < r && hash[s[r]] > 1) {
            hash[s[l]]--;
            l++;
        }
        
        maxLen = Max(maxLen, r - l + 1);
        
    }
    return maxLen;

}
```
