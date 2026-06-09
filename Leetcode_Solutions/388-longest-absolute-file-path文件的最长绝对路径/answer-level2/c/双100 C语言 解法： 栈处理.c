### 解题思路
栈处理的方法：
字符串是有规律的， \t的个数就是栈坐标，遇到含.文件的就计算

### 代码

```c
int lengthLongestPath(char * input){
    int len = strlen(input);
    if (len == 0) {
        return 0;
    }

    if (strchr(input, '.') == NULL) {
        return 0;
    }

    char *p = strchr(input, '\n');
    if (p == NULL) {
        if (strchr(input, '.')) {
            return len;
        }
        return 0;
    }

    int stack[5000] = {0};
    int top = 0;
    stack[top] = p - input;

    int max = 0;

    while (p != NULL) {
        char *cur = p + 1;
        while (*cur == '\t') {
            cur++;
        }

        top = cur - p - 1;
        char filename[1024] = {0};
        char *next = strchr(cur, '\n');
        int nameLen = 0;
        if (next == NULL) {
            nameLen = input + len - cur;
        } else {
            nameLen = next - cur;
        }

        memcpy(filename, cur, nameLen);
        stack[top] = nameLen;
        if (strchr(filename, '.')) {
            int tmp = -1;
            for (int i = 0; i <= top; i++) {
                tmp += (1 + stack[i]);
            }
            max = tmp > max? tmp : max;
        }
        p = next;
    }

    return max;
}
```