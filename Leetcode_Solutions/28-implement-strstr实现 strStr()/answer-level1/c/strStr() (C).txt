### 解题思路
暴力匹配很简单，重点是KMP。

### 代码
```c
int strStr(char * haystack, char * needle){
    if(needle == "")
        return 0;
    int n = strlen(haystack);
    int m = strlen(needle);
    int i = 0, j = 0;
    while(i <= n - m){
        while(j < m){
            if(haystack[i] != needle[j]){
                i = i - j + 1;
                j = 0;
                break;
            }
            else{
                i++;
                j++;
            }
        }
        if(j == m){
            return i - j; 
        }
    }
    return -1;
}
```