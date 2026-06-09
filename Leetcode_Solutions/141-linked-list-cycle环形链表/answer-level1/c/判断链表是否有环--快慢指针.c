### 解题思路
快慢指针，快指针一次走两步，慢指针一次走一步。
注意：第一次超时是因为 fast = fast->next; 没有正确处理fast的步幅导致。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 //快慢指针
 #include<stdbool.h>
bool hasCycle(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) { //相遇
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
```