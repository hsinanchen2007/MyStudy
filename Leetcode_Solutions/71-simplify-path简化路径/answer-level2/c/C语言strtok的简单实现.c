### 解题思路
通过strtok将字符串通过"/"分开，然后逐个通过压栈，出栈实现，很简洁的实现

### 代码

```c
#define MAX_NUM 1000

static char *g_stack[MAX_NUM] = {0};
static int g_stackCnt = 0;

static void Clear(void)
{
    memset(g_stack, 0, g_stackCnt * sizeof(char *));
    g_stackCnt = 0;
}

static void Push(char *data)
{
    if (g_stackCnt >= MAX_NUM) {
        return;
    }
    g_stack[g_stackCnt++] = data;
}

static void Pop(void)
{
    if (g_stackCnt <= 0) {
        return;
    }
    g_stack[--g_stackCnt] = NULL;
}

static bool Empty(void)
{
    return (g_stackCnt == 0);
}

char * simplifyPath(char * path){
    int i;
    char *p = NULL;
    char *delim = "/";
    char *result = NULL;
    
    if (path == NULL || strlen(path) == 0) {
        return path;
    }
    Clear();
    
    result = (char *)malloc((strlen(path) + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;
    }
    memset(result, 0, (strlen(path) + 1) * sizeof(char));
    result[0] = '/';
    
    p = strtok(path, delim);
    if (p != NULL) {
        if (strcmp(p, ".") != 0 && strcmp(p, "..") != 0) {
            Push(p);
        }
    }
    while ((p = strtok(NULL, delim)) != NULL) {
        if (strcmp(p, "..") == 0) {
            if (Empty() == false) {
                Pop();
            }
        } else if (strcmp(p, ".") != 0) {
            Push(p);
        }
    }
    
    for (i = 0; i < g_stackCnt; i++) {
        strcat(result, g_stack[i]);
        if (i != (g_stackCnt - 1)) {
            strcat(result, "/");
        }
    }
    
    return result;
}
```