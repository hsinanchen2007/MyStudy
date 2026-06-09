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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 0 || k == 1) {
            return head;
        }
        int count = 0;
        ListNode* node = head;
        while(node != NULL && count < k) {
            count++;
            node = node->next;
        }

        if (count != k) {
            return head;
        } else {
            ListNode* n_next = reverseKGroup(node, k);
            ListNode* pre = NULL;
            ListNode* cur = head;
            while(count-- > 0) {
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            head->next = n_next;
            return pre;
        }
     }
};
```