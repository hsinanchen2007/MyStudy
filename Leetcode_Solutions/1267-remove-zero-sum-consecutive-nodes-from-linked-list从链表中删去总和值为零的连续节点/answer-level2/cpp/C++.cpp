```
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *node = new ListNode(0);
        node->next = head;
        head = node;

        ListNode *cur = head;
        while (cur) {
            ListNode *p = cur->next;
            int sum = 0;
            int hit = false;
            while (p) {
                sum += p->val;
                if (sum == 0) {
                    cur->next = p->next;
                    hit = true;
                    break;
                }
                p = p->next;
            }
            if (!hit) {
                cur = cur->next;
            }
        }

        return head->next;
    }
};
```
