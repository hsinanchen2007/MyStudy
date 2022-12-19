
![image.png](https://pic.leetcode-cn.com/4a4b84a431b258189df3f333ed0eb9141166ad42fa73c10af69b519565f6b9ff-image.png)

typedef struct {
    char *path;
    int idx;
} MStack;

static inline void push(MStack *pStack, char c)
{
    pStack->path[pStack->idx++] = c;
}

static inline char pop(MStack *pStack)
{
    pStack->idx--;
    char c = pStack->path[pStack->idx];
    return c;
}

static inline char getTop(MStack *pStack) {
    return pStack->path[pStack->idx - 1];
}

char * simplifyPath(char *path) {
    int len = strlen(path);
    int idxLast = 0;
    size_t i;
    MStack stack;
    MStack *pStack = &stack;
    
    if (len < 1 || path[0] != '/') {
        return path;
    }
    stack.path = (char *)malloc(len + 1);
    memset(stack.path, 0, len + 1);
    stack.idx = 0;
    push(pStack, '/');
    idxLast = 1;
    for (i = 1; i < len; i++) {
        if (path[i] == '/') {
            if (i - idxLast == 0) {
                idxLast = i + 1;
            }
            else if (i - idxLast == 1 && path[i-1] == '.') {
                idxLast = i + 1;
            }
            else if (i - idxLast == 2 && path[i - 1] == '.' && path[i - 2] == '.') {
                if (pStack->idx > 1) {
                    pop(pStack);
                }
                while (getTop(pStack) != '/') {
                    pop(pStack);
                }
                idxLast = i + 1;
            }
            else {
                for (size_t j = idxLast; j <= i; j++) {
                    push(pStack, path[j]);
                }
                idxLast = i + 1;
            }
        }
    }
    if (i - idxLast == 0) {
        idxLast = i + 1;
    }
    else if (i - idxLast == 1 && path[i - 1] == '.') {
        idxLast = i + 1;
    }
    else if (i - idxLast == 2 && path[i - 1] == '.' && path[i - 2] == '.') {
        if (pStack->idx > 1) {
            pop(pStack);
        }
        while (getTop(pStack) != '/') {
            pop(pStack);
        }
        idxLast = i + 1;
    }
    else {
        for (size_t j = idxLast; j < i; j++) {
            push(pStack, path[j]);
        }
        idxLast = i + 1;
    }
    while (pStack->idx > 1 && getTop(pStack) == '/') {
        pop(pStack);
    }
    pStack->path[pStack->idx] = 0;
    strncpy(path, pStack->path, pStack->idx);
    path[pStack->idx] = 0;
    free(pStack->path);
    pStack->path = NULL;
    return path;
}