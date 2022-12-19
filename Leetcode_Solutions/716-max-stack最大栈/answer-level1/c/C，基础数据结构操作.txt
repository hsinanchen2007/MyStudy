## 基础链表操作
## 注意点：
1. 用例中有大负数情况
2. 使用动态内存分配可以得到较好的时间空间复杂度
3. 由于popMax是要求弹出靠近栈顶的最大值，所以压栈的时候最好使用头插法，这样遍历的时候第一次遍历到最大值，即可退出
## 代码
```
typedef struct node
{
    int value;
    struct node *next;
} MaxStack;

/** initialize your data structure here. */

MaxStack *maxStackCreate()
{
    MaxStack *head = (MaxStack *)malloc(sizeof(MaxStack));
    if (head == NULL)
    {
        return NULL;
    }
    head->next = NULL;
    return head;
}

void maxStackPush(MaxStack *obj, int x)
{
    MaxStack *node = (MaxStack *)malloc(sizeof(MaxStack));
    node->value = x;
    node->next = obj->next;
    obj->next = node;
}

int maxStackPop(MaxStack *obj)
{
    if (obj->next == NULL)
    {
        return -1;
    }
    MaxStack *tmp = obj->next;
    int rslt = tmp->value;
    obj->next = tmp->next;
    tmp->next = NULL;
    free(tmp);
    tmp = NULL;
    return rslt;
}

int maxStackTop(MaxStack *obj)
{
    if (obj->next == NULL)
    {
        return -1;
    }
    return obj->next->value;
}

int maxStackPeekMax(MaxStack *obj)
{        
    int max;
    MaxStack *tmp = obj->next;
    if(tmp != NULL) {
        max = tmp->value;
    }
    while (tmp != NULL)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
        }
        tmp = tmp->next;
    }
    return max;
}
int maxStackPopMax(MaxStack *obj)
{
    int max = maxStackPeekMax(obj);
    
    MaxStack *pre = obj;
    MaxStack *tmp = obj->next;

    while (tmp != NULL)
    {
        if (tmp->value == max)
        {
            pre->next = tmp->next;
            free(tmp);
            tmp = NULL;
            return max;
        }
        pre = tmp;
        tmp = tmp->next;
    }
    return max;
}
void maxStackFree(MaxStack *obj)
{
    MaxStack *tmp;
    while(obj != NULL) {
        tmp = obj;
        obj = obj->next;
        free(tmp);
    }
    tmp = NULL;
}
```