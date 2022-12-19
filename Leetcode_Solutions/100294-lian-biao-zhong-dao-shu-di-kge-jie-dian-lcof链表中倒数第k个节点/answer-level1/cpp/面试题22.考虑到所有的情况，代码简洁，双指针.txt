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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *beg, *end; beg = end = head;
        while (end && k--) end = end->next;
        while (end) beg = beg->next, end = end->next;
        return beg;
    }
};
```
