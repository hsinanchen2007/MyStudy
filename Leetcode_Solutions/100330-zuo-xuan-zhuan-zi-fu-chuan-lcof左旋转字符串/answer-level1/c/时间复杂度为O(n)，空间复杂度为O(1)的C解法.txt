### 解题思路
1. 分别转置前后子串
2. 转置整个字符串

### 代码

```c
//转置字符串，num为字符串长度
void reverseString(char* s, int num) {
    char temp;
    for(int i = 0; i < num / 2; i ++) {
        temp = s[i];
        s[i] = s[num - i - 1];
        s[num - i - 1] = temp;
    }
}

char* reverseLeftWords(char* s, int n){
    int count = 0;
    //计算字符串长度
    for(; s[count] != '\0'; count ++);
    //转置n个字符的子串
    reverseString(s, n);
    //转置n个字符后面的子串
    reverseString(s + n, count - n);
    //转置整个字符串
    reverseString(s, count);
    return s;
}
```