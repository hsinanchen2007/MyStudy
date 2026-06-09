### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize)
{
    
    struct ListNode *newhead=NULL;
    struct ListNode *pnext=head;
    struct ListNode *pnow=pnext;
    struct ListNode *ppre=NULL;
    struct ListNode *p;
    int *q,i=0;
    int a[20480];
    while(pnow)
    {
        pnext=pnow->next;
        pnow->next=ppre;
        ppre=pnow;
        pnow=pnext;
    }
    newhead=ppre;
    p=newhead;
    while(p)
    {
        a[i++]=p->val;
        p=p->next;
    }
    *returnSize=i;
    q=a;
    return q;
}
```