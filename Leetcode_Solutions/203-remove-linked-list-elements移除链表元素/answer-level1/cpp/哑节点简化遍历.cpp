### 解题思路
通过一个哑节点避开对头节点删除时的特殊处理

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (prev->next != NULL) {
            if (prev->next->val == val)
                prev->next = prev->next->next;
            else 
                prev = prev->next;
        }

        return dummy->next;
    }
};
```