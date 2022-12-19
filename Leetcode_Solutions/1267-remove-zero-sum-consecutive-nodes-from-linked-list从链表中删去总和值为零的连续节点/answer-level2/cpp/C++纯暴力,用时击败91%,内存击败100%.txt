
```
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* headSpace = new ListNode(INT_MIN);
        headSpace->next = head;

        bool havDelete = true;
        while (havDelete) {
            havDelete = false;
            for (ListNode* preHead = headSpace; preHead->next != nullptr; preHead = preHead->next) {
                int sum = 0;
                for (ListNode* curHead = preHead->next; curHead != nullptr; curHead = curHead->next) {
                    sum += curHead->val;
                    if (sum == 0) {
                        ListNode* destNode = curHead->next;
                        while (preHead->next != destNode) {
                            ListNode* tmp = preHead->next;
                            preHead->next = tmp->next;
                            // delete tmp;    
                        }
                        havDelete = true;
                        break;
                    }
                }
                if (havDelete) {
                    break;
                }
            }
        }
        ListNode* node = headSpace->next;
        delete headSpace;
        return node;
    }
};
```
