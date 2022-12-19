### 解题思路
此处撰写解题思路
(1)分配两个链表left/right
(2)轮循链表head，若其数据val小于x则把该节点挂在left上，不然就挂在right上
(3)将left与right拼接起来即是所求链表
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x)
{
    if(NULL==head)
        return NULL;
    struct ListNode * left=NULL,* right=NULL,* ret=head,*tp=NULL;
    while(head)
    {
        tp=head;
        if((head->val)<x)
        {
            head=head->next;
            if(left)
            {
                tp->next=left->next;
                left->next=tp;
            }
            else
            {
                tp->next=NULL;
                left=tp;
            }
        }
        else
        {
            head=head->next;
            if(right)
            {
                tp->next=right->next;
                right->next=tp;
            }
            else
            {
                tp->next=NULL;
                right=tp;
            }
        }
    }
    ret=left;
    if(NULL==left)
        ret=right;
    else
    {
        while(left->next)
            left=left->next;
        left->next=right;
    }
    return ret;
}
```