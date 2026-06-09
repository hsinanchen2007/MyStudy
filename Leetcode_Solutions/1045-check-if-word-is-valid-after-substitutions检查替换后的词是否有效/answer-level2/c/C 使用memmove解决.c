1. 寻找目标“abc”
2. 找到后将剩余字符串前移并重头开始匹配或者匹配下一个字符
3. 若最终start不为0,说明存在非“abc”字符串，返回false
4. 否则返回true
```
bool isValid(char * S){
    int len = strlen(S);
    int start = 0;
    int end = len;
    while (start < end) {
        if (S[start] == 'a' && S[start + 1] == 'b' && S[start + 2] == 'c') {
            memmove(S + start, S + start + 3, end - (start + 2));
            end = end - 3;
            start = 0;
        } else {
            start++;
        }
    }

    if (start != 0) {
        return false;
    }

    return true;
}
```
