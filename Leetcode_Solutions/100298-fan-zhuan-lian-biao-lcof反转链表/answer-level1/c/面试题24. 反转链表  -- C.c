### 解题思路
1. 采用前插入法反转

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *newhead = head;
    head = head->next;
    newhead->next = NULL; // 避免造成循环
    while (head != NULL) {
        struct ListNode *node = head->next;

        head->next = newhead; // 前插
        newhead = head;       // newhead重新指向新的头结点

        head = node;
    }
    return newhead;
}
```