### 解题思路
码一下哈哈哈，普通解法，下次补上动态规划啥的。

### 代码

```c
char * longestPalindrome(char * s){
    if(s=="")   return "";
    int size = strlen(s), max = 0, left = 0, right = 0;
    for(int step = 1; step <= 2; step++){
        for(int i = 0; i < size; i++){
            int j = step+i;
            if(j<size && s[i]==s[j]){
                int l = i-1, r = j+1;
                for(; l >= 0 && r < size && s[r]==s[l]; r++, l--){}
                if( max < (r-l-1) ){
                    max = r-l-1;
                    left = l+1;
                    right = r-1;
                }
            }
        }
    }
    if(max==0){
        char *res = malloc(sizeof(char)*2);
        res[0] = s[0];
        res[1] = '\0';
        return res;
    }
    char *res = (char*)malloc(sizeof(char) * (max+1));
    for(int i = left, index = 0; i <= right; i++, index++)
        res[index] = s[i];
    res[max] = '\0';
    return res;
}
```