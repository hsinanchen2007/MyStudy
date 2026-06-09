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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL)
        return l2;
    
    if(l2 == NULL)
        return l1;

    int num1,num2,sum,flag=0;
    struct ListNode* q = l1;
    struct ListNode* p = l2;
    struct ListNode* phead = (struct ListNode *)malloc(sizeof(struct ListNode));
    phead->val = 0;
    phead->next = NULL;
    struct ListNode* ptemp = phead;
    struct ListNode* pnew = NULL;
    while(q != NULL || p != NULL)
    {
        num2 = (p!=NULL)?p->val:0;
        num1 = (q!=NULL)?q->val:0;
       
        sum = num1+num2+flag;
        pnew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pnew->next = NULL;
        pnew->val = sum%10;
        ptemp->next = pnew;
        ptemp = pnew;
        flag = sum/10;
        if(q != NULL)
            q = q->next;
        if(p != NULL)
        p = p->next;
    }
    if(flag == 1)
    {
        pnew = (struct ListNode *)malloc(sizeof(struct ListNode));
        pnew->next = NULL;
        pnew->val = 1;
         ptemp->next = pnew;
    }
    ptemp = phead;
    phead = phead->next;
    free(ptemp);
    return phead;
}
```