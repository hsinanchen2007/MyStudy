### 解题思路
使用迭代实现链表反转

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
    if(head == NULL)
    {
        return NULL;
    }

    struct ListNode *newHead = NULL;
    struct ListNode *tmp;
    while(head)
    {
        tmp = head->next;
        head->next = newHead;
        newHead = head;
        head = tmp;
    }
    return newHead;
}
```