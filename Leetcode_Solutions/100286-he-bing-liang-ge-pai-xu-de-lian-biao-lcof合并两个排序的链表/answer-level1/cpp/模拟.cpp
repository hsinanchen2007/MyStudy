```cpp
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        ListNode* p = nullptr;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                p = l2;
                l2 = l2->next;
                p->next = nullptr;
                tail->next = p;
                tail = tail->next;
            }else{
                p = l1;
                l1 = l1->next;
                p->next = nullptr;
                tail->next = p;
                tail = tail->next;
            }
        }
        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }
        return dummy->next;
    }
};
```