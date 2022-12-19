### 解题思路
快慢指针，快指针走两步，慢指针走一步
需要注意的点是循环终止的判断条件，以及中途的判断
一定要在fast不是NULL的情况下才能取它的next，防止取空指针

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode *fast = head;
    struct ListNode *slow = head;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}
```