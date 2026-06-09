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
    ListNode* removeDuplicateNodes(ListNode* head) {

        if (!head || !head->next) return head;

        auto prev = head, cur = head->next;
        while (cur) {
            auto p = head;
            while (p != cur && p->val != cur->val)
                p = p->next;

            if (p == cur) prev = cur;
            else prev->next = cur->next;

            cur = cur->next;
        }

        return head;
    }
};
```