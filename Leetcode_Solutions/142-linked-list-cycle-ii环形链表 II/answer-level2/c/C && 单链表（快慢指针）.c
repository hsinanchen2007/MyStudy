### 解题思路
***参考官方题解***
快慢指针法
慢指针：走一步；
快指针：走两步；
若链表起始点与入环的第一个结点之间的距离为a；入环的第一个结点与相遇点之间的距离为b，环剩下长度为c；
则：2 * 慢指针走的距离 = 快指针走的距离

2 * （a + b） = a + (b + c) + b
可以得到：
a = c;
即：可以得到如下结论：
快慢指针相遇后，如果此时有一个慢指针从链表第一个结点出发，速度为每次走一步；与此同时，先前的慢指针也继续前进，则这两个指针会在入环的第一个结点处相遇，这样即可得到入环点。

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
    if (head == NULL) {
        return NULL;
    }
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *tempSlow = head;

    while ((fast != NULL) && (fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (slow != tempSlow) {
                slow = slow->next;
                tempSlow = tempSlow->next;
            }
            return slow;
        }
    }

    return NULL;
}
```