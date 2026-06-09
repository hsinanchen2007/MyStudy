```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* res = new ListNode(-1);
        ListNode* cur = res;
        while (l1 || l2 || c) {
            int temp = c;
            if (l1) {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                temp += l2->val;
                l2 = l2->next;
            } 
            c = temp >= 10 ? 1 : 0;
            cur->next = new ListNode(temp % 10);
            cur = cur->next;
        }
        return res->next;
    }
};
```
