滑动窗口一般用于解决找出查找满足一定条件的**连续区间**的性质（长度等）的问题。
找到滑动条件非常关键。

```
int max(int a, int b){
    return (a>b)?a:b;
}

int lengthOfLongestSubstring(char * s){
    int right = 0;
    int left = 0;
    int result = 0;

    while(s[right] != '\0'){
        for (int i = left; i < right; i++){
            if (s[right] == s[i]){
                left = i + 1;
            }
        }
        result = max(result, right-left+1);
        right++;
    }
    return result;
}
```
