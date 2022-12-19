class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* head_p = head;
        while(head)
        {
            if(head->next && head->val == head->next->val)
                head->next = head->next->next;
            else
                head = head->next;   
        }
        return head_p;
    }
};