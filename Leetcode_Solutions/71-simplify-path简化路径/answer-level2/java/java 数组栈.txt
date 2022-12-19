破玩意, 调了我半天
```java
    public String simplifyPath(String path) {
        path += '/';
        char[] chs = path.toCharArray();
        int top = -1;
        for (char c : chs) {
            if (top == -1 || c != '/') {
                chs[++top] = c;
                continue;
            }
            if (chs[top] == '/') {
                continue;
            }
            if (chs[top] == '.' && chs[top - 1] == '/') {
                top--;
                continue;
            }
            if (chs[top] == '.' && chs[top - 1] == '.' && chs[top - 2] == '/') {
                top -= 2;
                while (top > 0 && chs[--top] != '/') ;
                continue;
            }
            chs[++top] = c;
        }
        if (top > 0 && chs[top] == '/') top--;
        return new String(chs, 0, top + 1);
    }
```
