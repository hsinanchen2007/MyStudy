### 解题思路
    C实现代码量较大，简单题不划算。

### 代码

```c
typedef struct stack {
    char c;
    struct stack* next;
} stack;

inline stack* CreateStack(void)
{
    stack* head = (stack*)malloc(sizeof(stack));
    head->c = '\0';
    head->next = NULL;
    return head;
}

bool IsEmpty(stack* s)
{
    if (!s->next) {
        return true;
    }
    return false;
}

void PushStack(stack* head, char c)
{
    stack* newNode = (stack*)malloc(sizeof(stack));
    newNode->c = c;
    newNode->next = head->next;
    head->next = newNode;
    return;
}

bool PopStack(stack* head)
{
    if (IsEmpty(head)) {
        return false;
    }
    stack* pFree = head->next;
    head->next = head->next->next;
    free(pFree);
    return true;
}

inline void FreeStack(stack* head)
{
    stack* p;
    while (head) {
        p = head;
        head = head->next;
        free(p);
    }
    return;
}

int balancedStringSplit(char * s)
{
    if (!s) {
        return 0;
    }
    int idx = 0;
    int ret = 0;
    stack* head = CreateStack();
    while (s[idx] != '\0') {
        if (IsEmpty(head)) {
            PushStack(head, s[idx]);
            idx++;
            ret++;
            continue;
        }
        if (head->next->c != s[idx]) {
            PopStack(head);
        } else {
            PushStack(head, s[idx]);
        }
        idx++;
    }
    FreeStack(head);
    return ret;
}
```