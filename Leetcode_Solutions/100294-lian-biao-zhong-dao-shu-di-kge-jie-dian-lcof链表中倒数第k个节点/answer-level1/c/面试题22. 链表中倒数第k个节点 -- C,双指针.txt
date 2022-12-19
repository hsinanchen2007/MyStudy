### 解题思路
1.采用双指针，快指针首先往前移动K个节点，随后慢指针从头开始移动，当快指针移动到链表尾时，满指针指向倒数第K个节点(删除倒数第k个节点也可以使用这种方法)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
    if (head == NULL) {
        return NULL;
    }

    /* 快指针先往前移动k个节点 */
    struct ListNode *temp = head;
    while (temp != NULL && k-- > 0) {
        temp = temp->next;
    }

    /* 双指针，temp到达链表尾时，prev为倒数第k个节点 */
    struct ListNode *prev = head;
    while (temp != NULL) {
        prev = prev->next;
        temp = temp->next;
    }

    return prev;
}
```