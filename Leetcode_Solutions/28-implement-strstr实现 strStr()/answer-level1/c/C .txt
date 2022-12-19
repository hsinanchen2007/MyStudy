### 解题思路
暴力解法，遍历每一种可能，直到找到第一个满足条件的结果。

### 代码

```c
int strStr(char * haystack, char * needle){
    int h = strlen(haystack);
    int n = strlen(needle);
    if(!n)  return 0;
    int i;
    // h - n + 1 是指needle只可能存在于haystack[0...h-n]中的某个位置
    for(i = 0; i < h - n + 1; i++){
        int j = 0;
        for(; j < n; j++){
            if(haystack[i + j] != needle[j])
                break;
        }
        if(j == n)  return i;
    }
    return -1;
}


```