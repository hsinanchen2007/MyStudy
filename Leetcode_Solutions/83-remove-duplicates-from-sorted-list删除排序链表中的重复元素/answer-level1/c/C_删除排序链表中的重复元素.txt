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
    if(head==0)return 0;
    struct ListNode* iter=head;
    while(iter->next!=0)
    {
        if(iter->val==iter->next->val)
        {
            struct ListNode* del=iter->next;
            iter->next=del->next;
            free(del);      
        }
        else
            iter=iter->next;
    }
    return head;
}
```