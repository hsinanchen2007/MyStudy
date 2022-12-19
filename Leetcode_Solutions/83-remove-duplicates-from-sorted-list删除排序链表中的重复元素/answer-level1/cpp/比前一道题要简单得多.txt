### 解题思路


### 代码

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)return nullptr;
        ListNode* r = head, * l = head;
        int count = 0;
        while (1) {
            if (r->next == nullptr) {
                if (r != l) {
                    l->next = nullptr;
                }
                break;
            }
            else {
                r = r->next;
                if (l->val != r->val) {
                    l->next = r;
                    l = r;
                }
                
            }
        }
        return head;
    }
};
```