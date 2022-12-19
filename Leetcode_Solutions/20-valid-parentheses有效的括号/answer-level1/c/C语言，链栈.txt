### 解题思路


### 代码

```c
#include<stdio.h>
#include<stdlib.h>
typedef struct LNode
{
    char data;
    struct LNode *next;
}LNode;

LNode* initStack()
{
    LNode *lst;
    lst = (LNode*)calloc(1, sizeof(LNode));
    lst ->next = NULL;
    return lst;
}

int isEmpty(LNode *lst)
{
    if (lst->next == NULL)
        return 1;
    else
        return 0;
}

void push(LNode *lst, char x)
{
    LNode *p;
    p = (LNode*)calloc(1, sizeof(LNode));
    p->next = NULL;
    p->data = x;
    p->next = lst->next;
    lst->next = p;
}

int pop(LNode *lst, char *x)
{
    LNode *p;
    if (lst->next == NULL)
        return 0;
    p = lst->next;
    *x = p->data;
    lst->next = p->next;
    free(p);
    return 1;
}

bool isValid(char * s)
{
    LNode *lst;
    char pop_x = '\0';    //记录出栈元素
    char *pop_x_p = &pop_x;
    lst = initStack();
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            push(lst, s[i]);
        }
        else if (s[i] == ')' && pop(lst, pop_x_p) && pop_x == '(')
            continue;
        else if (s[i] == ']' && pop(lst, pop_x_p) && pop_x == '[')
            continue;
        else if (s[i] == '}' && pop(lst, pop_x_p) && pop_x == '{')
            continue;
        else
            return 0;
    }
    if (isEmpty(lst))
        return 1;
    else
        return 0;
}

```