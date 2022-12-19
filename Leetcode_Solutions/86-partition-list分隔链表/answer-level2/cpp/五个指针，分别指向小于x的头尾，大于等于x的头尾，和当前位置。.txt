### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode* pointer = head;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        ListNode* nexthead=nullptr;
        while (pointer != nullptr) {
            if (pointer->val < x) {
                if (pre == nullptr) head = pointer;
                else pre->next = pointer;
                pre = pointer;
            }
            else {
                if (next == nullptr) nexthead = pointer;
                else next->next = pointer;
                next = pointer;
            }
            pointer = pointer->next;
        }
        if (pre == nullptr) {
            next->next = nullptr;
            return nexthead;
        }

        if (nexthead != nullptr) {
            pre->next = nexthead;
            next->next = nullptr;
        }
        
        return head;
    }
};
```