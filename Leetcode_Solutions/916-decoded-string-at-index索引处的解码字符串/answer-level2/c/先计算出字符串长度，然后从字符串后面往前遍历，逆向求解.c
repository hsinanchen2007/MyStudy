### 解题思路
参考别人题解，先计算出字符串长度，然后从字符串后面往前遍历，逆向求解
通过K对长度取于找到余数为0 且为字符情况就是要返回的字符。打印下每一步执行结果可以看到详细求解过程


### 代码

```c
char g_ret[2];
char * decodeAtIndex(char * S, int K){
    long size = 0;
    int len;
    int i, cnt;
    char tmp;
    len = strlen(S);
    for (i = 0; i < len; i++) {
        if(isalpha(S[i])) {
            size++;
        } else {
            cnt = S[i] - '0';
            size = size * cnt;
        }
    }
    for (i = len - 1; i >= 0; i--) {
        K = K % size;
        g_ret[0] = S[i];
        if (K == 0 && isalpha(g_ret[0])) {
            g_ret[1] = 0;
            break;
        }
        if (isdigit(g_ret[0])) {
            size = size / (g_ret[0] - '0');
        } else {
            size--;
        }
    }  
    return g_ret;
}
  
```