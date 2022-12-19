**先找中点再反转后半部分**
1. 双指针找中点 ，可能前多后少，可能一样长
2. 反转后半部分
3. 再比较
```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow;
        slow=slow->next;
        fast->next=nullptr;
        ListNode* curr=slow? slow->next :nullptr;
        ListNode* next1=curr?curr->next:nullptr;
        slow=reverse(slow, curr, next1);
        while(head && slow)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        if(!head && !slow )
            return true;
        if( head && !head->next)
            return true;
        return false;        
    }
private:
    ListNode* reverse(ListNode* p, ListNode* curr , ListNode* next1)
    {
        ListNode* temp=p;
        while(curr)
        {
            curr->next=p;
           // curr->next=p;
            p=curr;
            curr=next1?next1:nullptr;
            next1=next1?next1->next:nullptr;
        }
        //prev->next=p;
        temp->next=nullptr;
        return p;
    }
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* fast=head,*slow=head;
        while(fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow;
        slow=slow->next;
        fast->next=nullptr;
        ListNode dummy(-1),*head2=&dummy;
        head2->next=slow;
        head2=reverse(head2,slow,slow?slow->next:nullptr);
        slow=head2->next;
        while(head && slow)
        {
            if(head->val!=slow->val)
            {
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        if(!head && !slow )
            return true;
        if( head && !head->next)
            return true;
        return false;        
    }
private:
    ListNode* reverse(ListNode* head2, ListNode* prev, ListNode* curr)
    {
        while(curr)
        {
           prev->next=curr->next;
           curr->next=head2->next;
           head2->next=curr;
           curr=prev?prev->next :nullptr;
        }      
        return head2;
    }
};
```
