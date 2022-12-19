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
        // 伪头结点
        ListNode* head = new ListNode(0);
        ListNode* first = head;
        while(l1 != NULL && l2!=NULL)
        {
            if(l1->val <= l2->val)
            {
                
                first->next = l1;
                first = first->next;
                l1 = l1->next;
            }
            else
            {
                first->next = l2;
                first = first->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL)
            first->next = l2;
        else
            first->next = l1;
        
        return head->next;

    }
};
```
