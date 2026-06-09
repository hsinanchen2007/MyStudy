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


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* p=head;
    if(head==NULL) return head;
    while(head->next!=NULL){
            if(head->val==head->next->val){
                head->next=head->next->next;             
            }
            else if(head->next!=NULL)
                head=head->next;
    }
    return p;
}
```