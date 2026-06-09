```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res=head;
        while(head!=NULL){
            if(head->next!=NULL){
                if(head->val==head->next->val){
                    head->next=head->next->next;
                    continue;
                } 
            }
           head=head->next;
        }
        return res;
    }
};
```
```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res=head;
        while(head!=NULL&&head->next!=NULL){
            if(head->val==head->next->val){
                head->next=head->next->next;
                continue;
            }
           head=head->next;
        }
        return res;
    }
};
```
