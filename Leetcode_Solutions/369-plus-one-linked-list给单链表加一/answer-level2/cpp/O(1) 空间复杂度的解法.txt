两次翻转链表即可。

```cpp
class Solution {
public:
    ListNode *plusOne(ListNode *head) {
        if (head == nullptr) return head;
        auto lst = reverse(head);
        auto cur = lst->next, pre = lst;
        pre->val += 1;
        
        while (cur != nullptr && pre->val > 9) {
            pre->val -= 10;
            cur->val += 1;
            pre = cur;
            cur = cur->next;
        }
        
        if (pre->val > 9) {
            pre->val -= 10;
            pre->next = new ListNode(1);
        }
        
        return reverse(lst);
    }

private:
    ListNode *reverse(ListNode *head) {
        if (head == nullptr)
            return head;
        
        ListNode *cur = head->next, *pre = head, *tmp = nullptr;
        pre->next = nullptr;
        
        while (cur != nullptr) {
            tmp = cur;
            cur = cur->next;
            tmp->next = pre;
            pre = tmp;
        }
        
        return pre;
    }
};
```