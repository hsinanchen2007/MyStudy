```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        auto p=&dummy;
        while(p->next&&p->next->next){
            auto p1=p->next;
            auto p2=p1->next;
            p->next=p2;
            p1->next=p2->next;
            p2->next=p1;
            p=p1;
        }
        return dummy.next;
    }
};
```
