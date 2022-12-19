### 解题思路
费时间费空间就是不费脑子
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
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;;
    }
    struct ListNode *p = reverseList(head->next);
    struct ListNode *q = p;
    while (q->next) {
        q = q->next;
    }
    q->next = head;
    head->next = NULL;
    return p;
}
```