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
    struct ListNode *prev = NULL,*cur = head;
    while(cur){
        struct ListNode* tail = cur->next;
        cur->next = prev;
        prev = cur;
        cur = tail;
    }
    return prev;
}
```