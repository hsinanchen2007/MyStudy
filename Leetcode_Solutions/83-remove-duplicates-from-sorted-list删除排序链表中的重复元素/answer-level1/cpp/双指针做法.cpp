### 解题思路
如果next已经为NULL了, 就不必要做current = next; next = current->next的操作了.

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* current = head;
        ListNode* next = head->next;

        while(next)
        {
            while (next && current->val == next->val)
            {
                next = next->next;
            }

            current->next = next;
            
            if (!next) break;
            current = next;
            next = current->next;
        }

        return head;
    }
};
```