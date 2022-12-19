class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        bool cycle = 0;
        while(slow && fast->next && slow->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                cycle = 1;
                break;
            }
        }
        if(cycle){
            ListNode *res=head;
            while(check!=slow){
                check=check->next;
                slow=slow->next;
            }
            return res;
        }else{
            return nullptr;
        }
    }
};