### 解题思路
设置两个指针，一个遇到重复数字则移动，一个遇到不同数字再移动

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
    if(head==NULL) return head;
    struct ListNode* low=head;
    struct ListNode* fast=head->next;
    while(fast)
    {
        if(low->val==fast->val)
        {
            fast=fast->next;
        }
        else
        {
            low->next=fast;
            low=fast;
            fast=low->next;
        }
    }
    low->next=NULL;
    return head;
}
```