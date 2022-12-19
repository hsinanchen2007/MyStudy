
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if(head == NULL || head->next ==NULL)
    {
        return head;
    }
    struct ListNode* p = head->next;
    head->next = swapPairs(p->next);
    p ->next = head;
    return p;
}
```