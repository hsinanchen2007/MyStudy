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


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* p=head;
    if(head==NULL) return head;
    while(p->next!=NULL)
        if(p->val==p->next->val)
            p->next=p->next->next;
        else p=p->next;
    return head;
}
```