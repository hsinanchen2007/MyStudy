```C++
class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int flag = 0) {
        if (l1 == nullptr && l2 == nullptr && flag == 0) {
            return nullptr;
        }
        ListNode *node = new ListNode(flag % 10);
        if (l1 != nullptr) {
            flag += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            flag += l2->val;
            l2 = l2->next;
        }
        node->val = flag % 10;
        node->next = addTwoNumbers(l1, l2, flag / 10);
        return node;
    }
};
```
