### 解题思路
拿字符串的空间当作栈，当然，这会破坏掉原来的字符串，但是好处是不需要重复遍历这个字符串，不需要知道这个字符串的长度，不需要开辟新的内存空间

### 代码

```c
bool isValid(char * s){
    int idx = -1;
    char* p = s;
    while (*p) {
        switch (*p) {
            case '(':
            case '[':
            case '{':
                s[++idx] = *p;
                break;
            case ')':
                if (idx < 0) {
                    return false;
                }
                if (s[idx] == '(') {
                    idx--;
                } else {
                    return false;
                }
                break;
            case '}':
                if (idx < 0) {
                    return false;
                }
                if (s[idx] == '{') {
                    idx--;
                } else {
                    return false;
                }
                break;
            case ']':
                if (idx < 0) {
                    return false;
                }
                if (s[idx] == '[') {
                    idx--;
                } else {
                    return false;
                }
                break;
            default:break;
        }
        p++;
    }
    if (idx >= 0) {
        return false;
    } else {
        return true;
    }
}
```