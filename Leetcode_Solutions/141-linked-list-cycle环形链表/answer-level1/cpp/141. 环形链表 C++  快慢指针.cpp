
如果存在环， 则快指针与慢指针肯定会在环中相遇。 可以类比在环形跑道中赛跑，快的肯定先会超过慢的，再追上慢的，在环中相遇（套圈）

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};