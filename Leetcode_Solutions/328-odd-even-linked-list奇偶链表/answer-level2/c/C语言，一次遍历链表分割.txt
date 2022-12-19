### 解题思路
此处撰写解题思路

分别指定奇数链表和偶数链表，最后将奇链表的末尾执行偶数链表的开头

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head){
    struct ListNode *odd, *even, *evenHead;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    odd = head;
    even = head->next;
    evenHead = head->next;

    while(odd->next != NULL && odd->next->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}
```