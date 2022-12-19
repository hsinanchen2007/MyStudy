```C++ []
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode *slow = head;
        ListNode *fast  = head->next;
        
        while(slow != fast){
            if(!fast || !fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

```

题目本身很多做法，用set来做相对容易想到也简单，感觉主要是这个快慢指针的思想，掌握后能在很多其他地方用到