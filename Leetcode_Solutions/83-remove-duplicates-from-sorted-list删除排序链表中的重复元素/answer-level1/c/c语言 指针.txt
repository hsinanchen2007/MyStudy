### 解题思路
在原链表上进行删除修改，设置指针指向链表

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if ( !head  )
    {
        return head;
    }
    struct ListNode* h= head;
    while(head->next!=NULL)
    {
        if(head->val==head->next->val)
        {
            head->next=head->next->next;
        }
        else
        {
            head=head->next;
        }
    }
    return h;
}
```