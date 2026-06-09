```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        auto dummy=new ListNode(0);
        dummy->next=head;
        int len=0;
        auto p=head;
        while(p){
            p=p->next;
            ++len;
        }
        for(int step=1;step<len+1;step<<=1){//这里len要+1
            auto tail=dummy;
            auto cur=dummy->next;
            while(cur){
                auto l1=cur;
                auto l2=cut(cur,step);
                cur=cut(l2,step);
                tail->next=merge(l1,l2);
                while(tail->next)tail=tail->next;
            }
        }
        return dummy->next;
    }
    ListNode* cut(ListNode* head,int n){
        if(head==NULL)return NULL;
        auto p=head;
        int i=1;
        while(p->next&&i++<n){
            p=p->next;
        }
        auto right=p->next;
        p->next=NULL;
        return right;
    }
    ListNode* merge(ListNode* l1,ListNode* l2){
        auto dummy=new ListNode(0);
        auto tail=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next=l1==NULL?l2:l1;
        return dummy->next;
    }
};
```
