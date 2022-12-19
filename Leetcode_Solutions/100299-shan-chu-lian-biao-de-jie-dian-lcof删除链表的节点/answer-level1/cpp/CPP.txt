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
    ListNode* deleteNode(ListNode* head, int val) {
        if(!head) return nullptr;
        if (head->val == val) return head->next;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;

        while (p) {
            if (p->val == val) {
                pre->next = p->next;
            }
            p = p ->next;
            pre = pre->next;
        }
        delete dummy;
        return head;
    }
};
```