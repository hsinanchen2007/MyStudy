

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //特殊性判断
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* first = l1;
        ListNode* second = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* l = dummy;
        while(first || second)
        {
            if(first == nullptr) 
            {
                l->next = second;
                l = l->next;
                second = second->next;
                continue;
            }
            if(second == nullptr)
            {
                l->next = first;
                l = l->next;
                first = first->next;
                continue;
            }

            if(first->val < second->val)
            {
                l->next = first;
                l = l->next;
                first = first-> next;
            }
            else
            {
                l->next = second;
                l = l->next;
                second = second->next;
            }
        }
        return dummy->next;
    }
};
```