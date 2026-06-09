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
    struct ListNode * first = (struct ListNode *)malloc(sizeof(struct ListNode));
    first->val = INT_MIN;
    first->next = NULL;
    struct ListNode * curr = first;
    while(head){
        if(curr->val != head->val){
            struct ListNode * p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->next = NULL;
            p->val = head->val;
            curr->next = p;
            curr = curr->next;
        }
        head = head->next;
    }
    return first->next;
}
```