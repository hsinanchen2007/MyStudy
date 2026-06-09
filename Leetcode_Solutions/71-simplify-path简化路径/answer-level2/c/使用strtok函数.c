利用``strtok``函数分割，``strcmp``比较字符串。c代码也可以写得简单一些。
建立一个栈，遇到..弹栈，遇到.跳过， 否则压栈。
```
#include <stdio.h>

#define MAXLEN 1024

typedef struct tagStack {
    char *data[MAXLEN];
    int top;
} Stack_S;

int pop(Stack_S *st, char *str)
{
    if (st->top < 0) {
        return -1;
    }
    if (str != NULL) {
        strcpy(str, st->data[st->top]);
    }
    st->top--;
    return 0;
}

int push(Stack_S *st, char *str)
{
    if (st->top >= MAXLEN) {
        return -1;
    }

    if (st->top < 0) {
        st->data[0] = str;
        st->top = 0;
    } else {
        st->data[++st->top] = str;
    }
    return 0;
}

char * simplifyPath(char * path)
{
    char *token;
    Stack_S  st;
    st.top = -1;  
    char *ret = (char*)malloc(strlen(path) + 1);
    if (ret == NULL) {
        return NULL;
    }
    token = strtok(path, "/");
    while (token != NULL) {
        // printf("token :%s\n", token);
        if (strcmp(token, "..") == 0) {
            pop(&st, NULL);
        } else if (strcmp(token, ".") != 0) {
            push(&st, token);
        }
        token = strtok(NULL, "/");
    }
    ret[0] = '\0';
    for (int i = 0; i <= st.top; i++) {
        // printf("ret:%s\n", ret);
        // printf("stdata %s\n", st.data[i]);
        sprintf(ret, "%s/%s", ret, st.data[i]);
    }
    if (strlen(ret) == 0) {
        ret[0] = '/';
        ret[1] = '\0';
    }
    // printf("ret %s\n", ret);
    return ret;

}
```