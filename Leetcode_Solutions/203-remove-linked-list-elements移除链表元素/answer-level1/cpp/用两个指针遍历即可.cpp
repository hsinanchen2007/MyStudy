一定要写在纸上把过程模拟一遍，画个图就很简单了
```
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
        auto dummy = new ListNode(-1);
        dummy->next = head;
        auto a = dummy, b = dummy;
        
        // draft in the paper first
        while(b) {
            b = a->next;
            while(b && b->val == val) {
                b = b ->next;
            }
    
            // delete val
            a->next = b;
            a = b;
        }

        return dummy->next;
        
    }
};

```
