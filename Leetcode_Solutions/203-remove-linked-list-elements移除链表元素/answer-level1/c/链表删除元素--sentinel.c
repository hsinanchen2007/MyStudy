### 解题思路
哨兵(sentinel)节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，
其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。
sentinel 即本题的dummy头。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//哨兵(sentinel)节点广泛应用于树和链表中，如伪头、伪尾、标记等，它们是纯功能的，通常不保存任何数据，
//其主要目的是使链表标准化，如使链表永不为空、永不无头、简化插入和删除。
//sentinel 即本题的dummy头
struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *sentinel = (struct ListNode*)calloc(1, sizeof(struct ListNode)); 
    sentinel->next = head;
    struct ListNode *curr = head;
    struct ListNode *prev = sentinel;

    while (curr != NULL) {
        if (curr->val == val) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
    return sentinel->next;
}
```