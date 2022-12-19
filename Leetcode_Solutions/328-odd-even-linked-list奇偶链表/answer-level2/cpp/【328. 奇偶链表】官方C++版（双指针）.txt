## 思路：双指针
### 代码
```c++
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *tmp = even;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = tmp;
        return head;
    }
};
```
