class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        
        if(!head || !head->next)
            return head;
        
        ListNode *pre,*cur;
        
        pre = cur = head;
        
        while(cur)
        {
            if(cur->val == pre->val)
            {
                cur = cur->next;
            }
            else
            {
                pre->next = cur;
                pre = cur;
            }            
        }
        pre->next = NULL;
        return head;
    }
};