- 看代码就能懂
```
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast) {
            slow = slow->next;
            fast = fast->next;
            if(fast) {
                fast = fast->next;
            }
        }
        
        return slow;
    }
};
```
