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
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) return head;
        ListNode* quick = head;
        ListNode* slow = head;
        while (slow && quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
        }

        return slow;
    }
};
```