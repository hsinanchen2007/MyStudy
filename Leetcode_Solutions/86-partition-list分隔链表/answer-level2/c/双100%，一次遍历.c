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


struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode lessHead = {0};
    struct ListNode moreHead = {0};
    struct ListNode *less = &lessHead;
    struct ListNode *more = &moreHead;

    struct ListNode *tmp = head;
    while (tmp != NULL) {
        if (tmp->val < x) {
            less->next = tmp;
            less = tmp;
        } else {
            more->next = tmp;
            more = tmp;
        }
        tmp = tmp->next;
    }
    less->next = moreHead.next;
    more->next = NULL;
    return lessHead.next;
}
```