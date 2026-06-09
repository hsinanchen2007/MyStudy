### 解题思路
此处撰写解题思路

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
        if (head == NULL) return NULL;
        int len = 0;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        for (;head;head = head->next) {
            len++;
        }

        int tail_k = k % len;
        if (tail_k == 0) return dummy->next;

        ListNode* first = dummy;
        ListNode* slow = dummy;
        for (int i = 0; i <= tail_k; ++i) {
            first = first->next;
        }

        ListNode* tail = NULL;
        while (slow && first) {
            slow = slow->next;
            tail = first;
            first = first->next;
        }

        auto temp = slow->next;
        tail->next = dummy->next;
        dummy->next = temp;
        slow->next = NULL;
        return dummy->next;
    }
};
```