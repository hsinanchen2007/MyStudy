### 解题思路
1.查找到链表的大小
2.循环找到倒数的值

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k) {
    struct ListNode* node = head;
    int size = 0;
    while (NULL!= node->next)
    {
        node = node->next;
        size++;
    }
    node = head;
    for (int i = 0; i < size - k + 1; i++)
        node = node->next;
    head = node;
    return head;
}
```