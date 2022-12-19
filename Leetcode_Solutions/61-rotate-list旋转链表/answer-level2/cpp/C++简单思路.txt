### 解题思路
双指针，当K大于链表长度时，只需翻转K%Length

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
         if (!head || k == 0) {
        return head;
    }

    ListNode *p = head;
    int length = 0;
    while (p) {
        p = p->next;
        length++;
    }

    int rotate = k % length;
    if (rotate == 0) {
        return head;
    }

    ListNode* q = head;
    while (rotate > 0 && q) {
        q = q->next;
        rotate--;
    }

    p = head;
    while (q->next) {
        p = p->next;
        q = q->next;
    }

    ListNode* newHead = p->next;
    p->next = NULL;
    q->next = head;
    return  newHead;
    }
};
```