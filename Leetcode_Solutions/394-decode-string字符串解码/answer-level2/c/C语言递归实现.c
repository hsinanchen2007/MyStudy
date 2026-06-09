### 解题思路
通过递归调用模拟压栈和出栈，  
遍历字符串，分为几种情况：  
1. 遇到字母，则保存至缓存中；  
2. 遇到数字，则更新计数值；  
3. 遇到"["，递归调用，将递归调用返回的结果复制N次到结果中；  
4. 遇到"]", 保存当前字符串指针所在的位置，并返回结果。  

### 代码

```c
#define STR_LEN 5000
char * decodeStringCore(char *s, char **e) {
    char *ret = (char*)malloc(sizeof(char) * STR_LEN);
    char *buf, *end = NULL;
    int count = 0, idx = 0;

    while(*s != '\0') {
        if (isalpha(*s)) {
            ret[idx++] = *s;
        } else if (isdigit(*s)) {
            count = 10 * count + *s - '0';
        } else if (*s == '[') {
            buf = decodeStringCore(s + 1, &end);
            while (count) {
                strcpy(ret + idx, buf);
                idx += strlen(buf);
                count--;
            }
            s = end;
        } else if (*s == ']') {
            *e = s;
            ret[idx] = '\0';
            return ret;
        }
        s++;
    }
    ret[idx] = '\0';
    return ret;
}

char * decodeString(char * s){
    char *end = NULL;
    return decodeStringCore(s, &end);
}

```
