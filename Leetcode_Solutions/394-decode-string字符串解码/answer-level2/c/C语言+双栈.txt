```
#define STACK_SIZE 1000

typedef struct {
    void** data;
    int top;
} Stack;

/* * initialize your data structure here. */
Stack* StackCreate()
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        return NULL;
    }

    stack->data = (void**)malloc(sizeof(void**) * STACK_SIZE);
    memset(stack->data, 0, sizeof(void**) * STACK_SIZE);
    stack->top = -1;

    return stack;
}

void StackPush(Stack* obj, void* x)
{
    if (obj->top == (STACK_SIZE - 1)) {
        return;
    }
    int top = obj->top;
    obj->data[++top] = x;
    obj->top = top;
    return;
}

void StackPop(Stack* obj)
{
    if (obj->top == -1) {
        return;
    }

    obj->top = obj->top - 1;
    return;
}

void* StackTop(Stack* obj)
{
    if (obj->top == -1) {
        return NULL;
    }

    return (obj->data[obj->top]);
}

bool isStackEmpty(Stack* obj)
{
    return (obj->top == -1);
}

void StackFree(Stack* obj)
{
    if (obj->data != NULL) {
        free(obj->data);
    }

    free(obj);
    return;
}

enum { STATUS_NUMBER = 0, STATUS_CHAR, STATUS_LEFT_SEPERATOR, STATUS_RIGHT_SEPERATOR };

int getStatus(char chr)
{
    if (chr >= '0' && chr <= '9') {
        return STATUS_NUMBER;
    }

    if (chr == '[') {
        return STATUS_LEFT_SEPERATOR;
    }

    if (chr == ']') {
        return STATUS_RIGHT_SEPERATOR;
    }

    return STATUS_CHAR;
}

bool isDigital(char chr)
{
    if (chr >= '0' && chr <= '9') {
        return true;
    }
    return false;
}

bool isChr(char chr)
{
    if (chr >= 'a' && chr <= 'z') {
        return true;
    }

    if (chr >= 'A' && chr <= 'Z') {
        return true;
    }

    return false;
}

void AppendStr(char* dst, char* src, int* index, int n)
{
    int size = strlen(src);

    for (int i = 0; i < n; i++) {
        strncpy(dst + *index, src, size);
        *index = *index + size;
    }

    return;
}

#define DECODE_BUFFER 10000
Stack* g_sStackNum;
Stack* g_sStackChar;
static int cpySize;
int g_index;

void DecodeStatusDeal(char Chr, char *ret)
{
    int deNodeNum = 0;
    /* 鉴于以下逻辑较为复杂，需要使用状态机表述，状态机包含数字，字符和左右分隔符四类 */
    switch (getStatus(Chr)) {
        case STATUS_NUMBER:
            cpySize = cpySize * 10 + Chr - '0';    // 10:十进制转换
            break;

        case STATUS_CHAR:
            ret[g_index++] = Chr;
            break;

        case STATUS_LEFT_SEPERATOR:
            /* 数字压入数字栈 */
            StackPush(g_sStackNum, (void *)(cpySize));
            cpySize = 0;

            /* 字符串压入字符栈 */
            char* store = (char*)malloc(sizeof(char) * (g_index + 1));
            ret[g_index] = '\0';
            strncpy(store, ret, g_index + 1);
            StackPush(g_sStackChar, (void*)store);
            memset(ret, 0, DECODE_BUFFER);
            g_index = 0;
            break;

        case STATUS_RIGHT_SEPERATOR:
            /* 出栈处理 */
            deNodeNum = (int)StackTop(g_sStackNum);
            StackPop(g_sStackNum);

            char tmp[DECODE_BUFFER] = {0};
            int idx = 0;
            AppendStr(tmp, ret, &idx, deNodeNum);

            memset(ret, 0, DECODE_BUFFER);

            char* chr = (char*)StackTop(g_sStackChar);
            if (chr != NULL) {
                StackPop(g_sStackChar);
                strncpy(ret, chr, strlen(chr));
                ret[strlen(chr)] = '\0';
                free(chr);
            }

            strcat(ret, tmp);
            g_index = strlen(ret);

            break;

        default:
            break;
    }
}

char* decodeString(char* s)
{
    if (s == NULL) {
        return NULL;
    }
    int size = strlen(s);
    g_index = 0;
    cpySize = 0;

    /* 定义返回数组 */
    char* ret = (char*)malloc(sizeof(char) * DECODE_BUFFER);
    memset(ret, 0, sizeof(char) * DECODE_BUFFER);

    /* 创建两个栈，一个数字栈，一个字符栈 */
    g_sStackNum = StackCreate();
    g_sStackChar = StackCreate();

    for (int i = 0; i < size; i++) {
        DecodeStatusDeal(s[i], ret);
    }

    StackFree(g_sStackNum);
    StackFree(g_sStackChar);

    return ret;
}
```
