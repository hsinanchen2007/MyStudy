class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        //第一次判断是否为空
        if ( head == NULL || head->next == NULL)
        {
            return false;
        }
        
        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        
        while( slow!= fast )
        {
            //第二次判断是否为空
            if ( fast == NULL || fast->next == NULL )
            {
                return false;    
            }
            
            slow = slow->next;
            
            fast = fast->next->next;
            
            
        }
                
        
        return true;
    }
    
    
    
};