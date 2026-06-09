### 解题思路
此处撰写解题思路

### 代码

```c

#define MAX_DIR 100
#define MAX_DEP 1000

typedef struct {
    char buf[MAX_DIR];
}SNode;

typedef struct {
    SNode data[MAX_DEP];
    int size;
}Stack;

Stack *create() {
    Stack *st = malloc(sizeof(Stack));
    st->size = 0;
    return st;
}

void push(Stack *st, const char *str, int len) {
    st->size++;
    memcpy(st->data[st->size].buf, str, len);
    st->data[st->size].buf[len] = '\0';
}

void pop(Stack *st) {
    st->size--;
}

bool empty(Stack *st) {
    return st->size == 0;
}

void dump(Stack *st) {
    for (int i = 1; i <= st->size; ++i) {
        printf("%s\n", st->data[i].buf);
    }
}

char * simplifyPath(char * path){
    Stack *s = create();
    char buf[MAX_DIR];
    int buf_index = 0;
    int counter = 0;
    while (*path != '\0') {
        if (*path != '/') {
            buf[buf_index++] = *path;
            if (*path == '.') {
                ++counter;
            } else {
                counter = 0;
            }
        } else if (*path == '/') {
            if (counter == 2) {
                if (!empty(s)) {
                    pop(s);
                }
                counter = 0;
                buf_index = 0;
            }
            if (counter == 1) {
                buf_index = 0;
                counter = 0;
            }
            if (buf_index != 0) {
                push(s, buf, buf_index);
                buf_index = 0;
            }
        }
        ++path;
    }
    if (buf_index != 0 && (counter == 0 || counter > 2)) {
        push(s, buf, buf_index);
    }
    if (counter == 2 && !empty(s)) {
        pop(s);
    }
    // dump(s);
    char *ans = malloc(MAX_DEP);
    ans[0] = '/';
    int index = 1;
    char *cursor = ans + 1;
    if (!empty(s)) {
        for (int i = 1; i <= s->size; ++i) {
            int subLen = strlen(s->data[i].buf);
            memcpy(cursor, s->data[i].buf, subLen);
            index += subLen;
            cursor = cursor + subLen;
            if (i != s->size) {
                *cursor = '/';
                cursor++;
                index++;
            }
        }
    }
    ans[index] = '\0';
    return ans;
}
```