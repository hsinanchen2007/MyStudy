### 解题思路
![image.png](https://pic.leetcode-cn.com/bd6763e4a0726f155f5df0849672747baca8601b21bcd0d0b6d286d5cbfd81b6-image.png)


### 代码

```c
char * reverseWords(char * s){
    char* ret = (char*)malloc(sizeof(char) * 100000);
    if(strlen(s) == 0) {
        return s;
    }
    int i;
    for(i = 0; i < strlen(s); i++) {
        if(s[i] != ' ') {
            break;
        }
    }
    if(i == strlen(s)) {
        ret[0] = '\0';
        return ret;
    }
    int len;
    int j, k, index;
    int sum = 0;
    
    int returnsize = 0;
    for(i = strlen(s) - 1; i >= 0; i--) {
        if(s[i] != ' ') {
            break;
        }
    }
    index = i;
    for(i = index; i >= 0; i = j) {
        for(j = i; j >= 0; j--) {
            if(s[j] == ' ') {
                break;
            }
        }
        len = i - j;
        for(k = 0; k < len; k++) {
            ret[sum + k] = s[j + k + 1];
        }
        ret[sum + len] = ' ';
        sum += (len + 1);
        for(; j >= 0; j--) {
            if(s[j] != ' ') {
                break;
            }
        }
    }
    ret[sum - 1] = '\0';
    return ret;
}
```