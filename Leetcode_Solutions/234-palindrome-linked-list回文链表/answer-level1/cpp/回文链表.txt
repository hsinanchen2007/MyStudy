```
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) return true;
        
        ListNode *slow=head, *fast=head;
        vector<int> intStack;
        while(fast!=NULL && fast->next!=NULL){
            intStack.push_back(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast==NULL){
            //说明偶数个节点;
        }else{
            //说明奇数个节点;
            slow = slow->next;
            
        }
        while(slow!=NULL && slow->val==*intStack.rbegin()){
            intStack.pop_back();
            slow = slow->next;
        }
        return intStack.empty();
    }
```
