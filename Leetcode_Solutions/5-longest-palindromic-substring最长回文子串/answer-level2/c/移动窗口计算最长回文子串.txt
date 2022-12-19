### 解题思路
此处撰写解题思路

### 代码

```c
int isPalindrome(char *s, int length){
    if(length <= 1) {
        return 1;
    }
    if(*s == *(s + length - 1)) { // 两端的值一样
        return isPalindrome(++s,length - 2);
    }
    return 0;
}

char * longestPalindrome(char * s){

    int max = strlen(s); // 窗口大小
    if(max <= 1) {
        return s;
    }
    int count = max; // 窗口移动范围

    while (max > 0){
        // 移动窗口
        int start = 0;
        int length = max;
        while(start + length <= count){
            // 判断是否回文
            if(isPalindrome(s + start, length)) {
                s = s + start;
                s[length] = '\0';
                return s;
            }
            start++;
        }
        max--;// 每次循环，窗口大小减一
    }
    return NULL;
}

```