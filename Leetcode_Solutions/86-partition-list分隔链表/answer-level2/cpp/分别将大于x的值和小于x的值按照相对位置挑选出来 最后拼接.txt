```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       ListNode* HEAD1=new ListNode(0);//创建一个头结点
        ListNode*HEAD2=new ListNode(-1);//创建另一头结点
        ListNode* p;
        ListNode*q;
        p=HEAD1;
        q=HEAD2;
       
        while(head!=nullptr){
            if(head->val<x){
                p->next=head;
                p=p->next;
            }
            if(head->val>=x){
                q->next=head;
                q=q->next;
            }
            head=head->next;
        }
        p->next=HEAD2->next;
        q->next=nullptr;
        return  HEAD1->next;
    }
};
```
