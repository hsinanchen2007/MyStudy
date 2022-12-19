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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        auto cur = dummy;
        while(cur->next && cur->next->next){
            auto a = cur->next,b = cur->next->next;
            cur->next = b;
            a->next = b->next;
            b->next = a;
            cur = a;
        }
        return dummy->next;
    }
};
```