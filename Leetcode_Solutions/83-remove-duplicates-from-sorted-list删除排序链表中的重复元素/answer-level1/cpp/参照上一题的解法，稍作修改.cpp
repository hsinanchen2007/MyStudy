```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* HEAD=new ListNode(0);
        HEAD->next=head;
        ListNode* cur=HEAD;
        while(cur->next!=nullptr){
           while(cur->next->next!=nullptr&&cur->next->val==cur->next->next->val){
                ListNode* temp=cur->next->next;
                cur->next->next=temp->next;
                delete temp;
            }
            cur=cur->next;            
        }
        return  HEAD->next;
    }
};
```
