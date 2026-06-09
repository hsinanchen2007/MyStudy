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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> us;
        ListNode* dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while(pre->next) {
            if(us.count(pre->next->val)) {
                ListNode * tmp = pre->next;
                pre->next = pre->next->next;
                delete tmp;
            }
            else {
                us.insert(pre->next->val);
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};
```
