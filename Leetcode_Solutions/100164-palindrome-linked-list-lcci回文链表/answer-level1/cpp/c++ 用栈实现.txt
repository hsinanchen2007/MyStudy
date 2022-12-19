```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        stack<ListNode*> stk;
        ListNode* fast=head;
        ListNode* slow=head;
        stk.push(NULL);
        ListNode* temp=NULL;
        while(fast && fast->next){
            fast=fast->next->next;
            temp=slow->next;
            slow->next=stk.top();
            stk.push(slow);
            slow=temp;
        }
        if(!fast){
            while(slow){
                if(slow->val!=stk.top()->val) return false;
                stk.pop();
                slow=slow->next;
            }
        }
        else{
            slow=slow->next;
            while(slow){
                if(slow->val!=stk.top()->val) return false;
                stk.pop();
                slow=slow->next;
            }
        }
        return true;
    }
};
```
