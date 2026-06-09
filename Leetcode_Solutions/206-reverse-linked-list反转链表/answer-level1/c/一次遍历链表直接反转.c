### 解题思路
一次遍历链表，把当前链表指向的下一个节点先保存，然后把当前节点的下一个节点反转，指向前一个，循环上述过程，直到next到达链表尾部

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode *head){

    struct ListNode *cur = NULL;
    struct ListNode *next = head;
    struct ListNode *tmp = NULL;
    while (next != NULL) {
        tmp = next->next;
        next->next = cur;
        cur = next;
        next = tmp;
    }
    return cur;
}
```