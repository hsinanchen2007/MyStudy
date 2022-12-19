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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    struct ListNode *p=headA;
    struct ListNode *q=headB;
    while(p!=NULL)
    {
        q=headB;
        while(q)
        {
            if(q==p)
            return q;
            else
            q=q->next;
        }
        p=p->next;
    }
    return NULL;
}
```