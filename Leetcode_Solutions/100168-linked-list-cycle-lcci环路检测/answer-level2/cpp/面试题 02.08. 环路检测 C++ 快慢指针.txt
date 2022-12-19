### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast)
                break;
        }

        if(fast == nullptr || fast->next == nullptr)
            return nullptr;

        ListNode* p1 = head;
        ListNode* p2 = fast;

        while(p1 != p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }

        return p1;
    }
};
```