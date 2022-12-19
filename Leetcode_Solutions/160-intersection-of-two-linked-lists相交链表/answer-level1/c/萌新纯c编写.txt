### 解题思路
首先链表长度要相同，才能保证两个指针遍历时同步进行。

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
    if(headA==NULL||headB==NULL)return 0;
    struct ListNode*l1=headA;
    struct ListNode*l2=headB;
    while(l1!=NULL&&l2!=NULL)
        {
            l1=l1->next;
            l2=l2->next;
        }//比较链表长度
    if(l1==NULL)
        {
            l1=headB;
            while(l2!=NULL)
            {
                l1=l1->next;
                l2=l2->next;
            }
            l2=l1;
            l1=headA;
        }
    else
        {
            l2=headA;
            while(l1!=NULL)
            {
                l1=l1->next;
                l2=l2->next;
            }
            l1=l2;
            l2=headB;
        }//砍掉过长的部分，使两个链表的长度一样；
    while(l1!=NULL&&l2!=NULL)
    {
        if(l1==l2)return l1;
        l1=l1->next;l2=l2->next;
    }//比较和指针的值
return 0;
}
```