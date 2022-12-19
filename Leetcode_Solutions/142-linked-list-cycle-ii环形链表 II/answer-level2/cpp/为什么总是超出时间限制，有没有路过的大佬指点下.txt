代码如下
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return NULL;
        ListNode *fast=head->next;
        ListNode *slow=head;
        while(fast!=slow){
            if(fast->next==NULL||fast->next==NULL)return NULL;
            fast=fast->next->next;
            slow=slow->next;
        }
        slow=head;
        while(slow!=fast){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;  
    } 
};