```
class Solution {
public:
    bool isOK = true;
    void helper(ListNode* head,ListNode* &h){
        if(head==NULL)
            return;
        helper(head->next,h);
        if(h->val!=head->val)
            isOK=false;
        h=h->next;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* h=head;
        helper(head,h);
        return isOK;
    }
};
```
