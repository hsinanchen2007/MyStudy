
### 代码

```cpp
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast->next){
                fast = fast->next;
            }
        }
        return slow;
    }
};
```