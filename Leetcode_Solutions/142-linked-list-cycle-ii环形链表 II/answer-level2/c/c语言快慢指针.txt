### 解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;
    struct ListNode * fast = head->next, *slow = head;
    // 循环的控制条件为 快指针是否指向NULL(因为循环链表中不会出现NULL) 及 快慢指针是否相等
    while(fast != NULL && fast->next != NULL && slow != fast) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // 如果快慢指针相等， 那么说明该链表存在循环
    if(slow == fast) {
        // 有环 
        struct ListNode * pre = head, * meet = fast;
        while(meet->next != pre) {
            pre = pre->next;
            meet = meet->next;
        }
        return pre;
    }

    return NULL;
 }
```