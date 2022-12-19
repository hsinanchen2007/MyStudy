使用strtok函数以'/'为分隔符全部分隔开，然后判断每一个子子字符串。
```
char * simplifyPath(char * path){
    const char token[2] = "/";
    char *subPath, *res;
    char s[1000];
    int top = -1, idx = 0;

    subPath = strtok(path, token);
    while (subPath != NULL) {
        if (strcmp(subPath, ".") != 0 && strcmp(subPath, "..") != 0) { // subpath不等于'.'或是'..'，将字符串压栈
            if (top == -1 || s[top] != '/') { // 若是栈顶字符为空，或是不为'/'，在栈顶加入'/'
                s[++top] = '/';
            }
            while (subPath[idx] != '\0') { // 将subPath入栈
                s[++top] = subPath[idx];
                idx++;
            }
            idx = 0;
        }
        else if (strcmp(subPath, "..") == 0) { subpath等于'..'，将前一个subPath出栈
            if (top == -1) { // 若栈顶无字符，加入'/'
                s[++top] = '/';
            }
            else if (top != 0) { // 当栈中不仅存在根目录'/'时，将上一个subPath出栈
                while (s[top] != '/') {
                    top--;
                }
                if (top != 0) top--;
            }
        }
        subPath = strtok(NULL, token);
    }
    if (top == -1) { // 当path为根目录'/'或是'///'等字符串时，subPath == NULL，此时top == -1
        s[++top] = '/';
    }

    res = (char *)malloc((top + 2) * sizeof(char));
    res[top + 1] = '\0';
    for (int i = 0; i <= top; i++) {
        res[i] = s[i];
    }
    return res;
}
```
