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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* curr = head;
        while (l1 != NULL && l2 != NULL){
            if (l1->val <= l2->val){
                curr->next = l1;
                curr = curr->next;
                l1 = l1->next;
            }else{
                curr->next = l2;
                curr = curr->next;
                l2 = l2->next;
            }
        }
        while (l1 != NULL){
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
        }
        while (l2 != NULL){
            curr->next = l2;
            curr = curr->next;
            l2 = l2->next;
        }
        return head->next;
    }
};
```