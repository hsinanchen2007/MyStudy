```cpp
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* tail = head;
        while(k) {
            tail = tail->next;
            k--;
        }
        while (tail) {
            head = head->next;
            tail = tail->next;
        }
        return head;
    }
};
```