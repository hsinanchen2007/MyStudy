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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode* new_begin = new ListNode(-1);
        new_begin->next = head;
        ListNode* begin;  
        ListNode* curr = head->next;   
        head->next = NULL;   
        while(curr)
        {
            begin = new_begin; 
            while(begin->next && (begin->next)->val <= curr->val)
            {
                begin = begin->next;
            }
            ListNode* next = curr->next;
            curr->next = begin->next;
            begin->next = curr;          
            curr = next;
        } 
        return new_begin->next;
    }
};
```
