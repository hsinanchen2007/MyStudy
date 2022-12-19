### 解题思路
此处撰写解题思路

### 代码

```c
#if 1
#define LEN_STR 5000
#define LEN_TMP 2000
char * decodeString(char * s)
{
    char *stack;
    char *tmp;

    /* 特判 */
    if (s == NULL) {   
        return NULL;
    }

    stack = (char *)malloc(LEN_STR);
    memset(stack, 0, LEN_STR);
    tmp = (char *)malloc(LEN_TMP);
    memset(tmp, 0, LEN_TMP);
    
    int top = 0;
    int strcnt = 0;
    int numcnt = 0;
    char arr[500] = {0}; 
    for (int i = 0; i < strlen(s); i++) {        
        
        if (s[i] == ']') {
            strcnt = 0;
            while (stack[top] != '[') {
                tmp[strcnt++] = stack[top];
                stack[top] = 0;
                top--;
            }

            stack[top] = 0;
            top--;

            numcnt = 0;
            while (top != 0 && isdigit(stack[top])) {
                arr[numcnt++] = stack[top--];
            }
            int num = 0;
            for (int m = numcnt - 1; m >=0 ; m--) {
                num = (num * 10 + arr[m] - '0');
            }

            while (num--) {
                for (int p = strcnt - 1; p >= 0; p--) {
                    stack[++top] = tmp[p];
                }
            }
        } else {
            stack[++top] = s[i];
        }
    }

    free(tmp);
    return stack + 1;
}

#endif
```