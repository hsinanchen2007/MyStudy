```
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *p1 = head, *p2 = head;
        while(p1) {
            if(k>0) {
                p1 = p1->next;
                k--;
            } else {
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return p2;
    }
};
```
