### 解题思路

![image.png](https://pic.leetcode-cn.com/04b1f377ad3d4c3d65c6f37128a13f61d590d552ea04920024bb54752fd5c4d0-image.png)

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
    struct ListNode *slow = NULL;
    struct ListNode *fast = NULL;
    if (head == NULL) {
        return head;
    }
    slow = fast = head;
    while(1) {
        if (fast->next == NULL || fast->next->next == NULL) {
            break;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return fast->next == NULL ? slow : slow->next;
}
```