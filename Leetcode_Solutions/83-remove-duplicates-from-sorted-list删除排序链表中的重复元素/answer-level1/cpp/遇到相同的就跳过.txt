### 解题思路


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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode *p = head;
        while (p)
        {
            ListNode *cur = p;
            int value = p->val;
            while (p->next && p->next->val == value)
            {
                p = p->next;
            }
            p = p->next;
            cur->next = p;
        }
        return head;
    }
};
```