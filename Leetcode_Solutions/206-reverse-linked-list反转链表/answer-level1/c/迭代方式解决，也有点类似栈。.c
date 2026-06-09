### 解题思路
迭代方式解决，也有点类似栈。

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

    struct ListNode *list[10000] = { NULL };
    struct ListNode *tmp = head;
    int index = 0;
    while (tmp) {
        list[index++] = tmp;
        tmp = tmp->next;
    }

    index--;
    struct ListNode *nodeHead = list[index];
    while (index > 0) {
        list[index]->next = list[index - 1];
        index--;
    }
    list[0]->next = NULL;

    return nodeHead;
}
```