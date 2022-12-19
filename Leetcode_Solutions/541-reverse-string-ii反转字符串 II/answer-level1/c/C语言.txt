### 解题思路
读题2小时，代码5分钟

### 代码

```c
void reverse(char *s, int start, int end) {
    while(start < end) {
        char tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}
char * reverseStr(char * s, int k){
    for (int i = 0; i < strlen(s); i += 2 * k) {
        if (strlen(s) - 1 - i >= k) {
            reverse(s, i, i + k - 1);
        } else {
            reverse(s, i, strlen(s) - 1);
        }
    }
    return s;
}
```