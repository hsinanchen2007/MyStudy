### 解题思路
窗口大小：i~j
用hashmap来检查某字符是否在窗口中

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int n = strlen(s);
    int hashmap[95] = {0};
    int max = 0;
    int i = 0, j = 0;
    int tmp;
    while(i < n && j < n){
        tmp = s[j] - ' ';
        if(hashmap[tmp] == 0){
            hashmap[tmp]++;
            j++;
            max = max > (j - i) ? max : (j - i);
        }else{
            tmp = s[i] - ' '; 
            hashmap[tmp] = 0;
            i++;
        }
    }
    return max;
}
```