### 解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* cur=NULL,*pre=head;
    while(pre!=NULL)
    {
        struct ListNode* t=pre->next;
        pre->next=cur;
        cur=pre;
        pre=t;
    }
    return cur;
}
```