### 解题思路
此处撰写解题思路

### 代码

```c
bool isValid(char * s){
    char data[10000] = {0};
    int head = 0;
    int i = 0;
    bool todoNext = false;
    bool invalid = true;

    if (s == NULL || s[0] == '\0') {
        return invalid;
    }

    data[head++] = s[i++];
    while (s[i] != '\0') {
        switch (s[i]) {
            case ')': {
                if (head > 0 && data[head - 1] == '(') {
                    head--;
                    i++;
                    todoNext = true;
                }
                break;
            }
            case '}': {
                if (head > 0 && data[head - 1] == '{') {
                    head--;
                    i++;
                    todoNext = true;
                }
                break;
            }
            case ']': {
                if (head > 0 && data[head - 1] == '[') {
                    head--;
                    i++;
                    todoNext = true;
                }
                break;
            }
            default: {
                break;
            }
        }
        if (todoNext == false) {
            data[head++] = s[i++]; 
        } else {
            todoNext = false;
        }
    }

    if (head != 0) {
        invalid = false;
    }

    return invalid;
}
```