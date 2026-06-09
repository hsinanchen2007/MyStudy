### 解题思路
一个快指针，一个慢指针循环检索，快指针每次两步，满指针每次一步，如果有环，必定相遇。
相遇的位置，和起始位置的中间就是相交的节点。

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

    struct ListNode *fast;
    struct ListNode *slow;
    struct ListNode *meet;

    fast = head;
    slow = head;
    meet = NULL;

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;

        if (!fast)
        {
            return NULL;
        }

        fast = fast->next;
        
        if (fast == slow)
        {
            meet = fast;
            break;
        }
    }
    if (!meet)
    {
        return NULL;
    }
    
    while (head && meet)
    {
        if (head == meet)
        {
            return head;
        }
        
        head = head->next;
        meet = meet->next;
    }
    
    return NULL;

}
```