
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node
{
    int val;
    struct Node* next;
}node,*pnode;


typedef struct Stack
{
    pnode ptop;
    pnode pbase;
}stack,*pstack;

stack init_stack()
{
    pnode phead = (pnode)malloc(sizeof(node));
    stack S;
    S.pbase = S.ptop = phead;
    phead->next = NULL;
    return S;
}

void push(pstack ps,int val)
{
    pnode pnew = (pnode)malloc(sizeof(node));
    pnew ->val = val;
    pnew ->next = ps->ptop;
    ps ->ptop = pnew;
    return;
}

void pop(pstack ps)
{
    pnode p = ps->ptop->next;
    free(ps->ptop);
    ps->ptop = p;
    return;
}

int getElem(pstack ps)
{
    int a = ps->ptop->val;
    return a;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    stack s = init_stack();
    int i;
    int a[10000];
    for(i=0;i<nums2Size;i++)
    {
        if(s.ptop == s.pbase)
        {
            push(&s,nums2[i]);
            continue;
        }
        if(nums2[i]<=getElem(&s))
        {
            push(&s,nums2[i]);
        }
        else
        {
            while(getElem(&s) < nums2[i] && s.ptop != s.pbase)
            {
                a[getElem(&s)] = nums2[i];
                pop(&s);
            }
            push(&s,nums2[i]);
        }
    }
    while(s.ptop != s.pbase)
    {
        a[getElem(&s)] = -1;
        pop(&s);
    }
    int* renums = (int*)malloc(sizeof(int)*nums1Size);
    for(i=0;i<nums1Size;i++)
    {
        renums[i] = a[nums1[i]];
    }
    *returnSize = i;
    free(s.pbase);
    return renums;
}
```