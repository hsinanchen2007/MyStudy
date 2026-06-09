### 解题思路
依次排查最大的字符区间

### 代码

```c
int lengthOfLongestSubstring(char * s){
    if(strlen(s) < 2 ){
        return strlen(s);
    }
    int pre = 0;
    int i = 0;
    int j = 0;
    int max = 0;
    while(s[i] != '\0'){
        for(j = pre; j < i; j++){
            if(s[j] == s[i]){
                if((i - pre) > max){
                    max = i - pre;
                }
                pre = j + 1;
            }
        }
        i++;
    }
    return (max > (i - pre))?max:(i - pre);
}
```