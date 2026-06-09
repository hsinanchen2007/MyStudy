归并排序求解，如下：
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
        return mergeList(head);
    }
    ListNode* mergeList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode *slow=head,*fast=head,*pre=head;
        while(fast && fast->next){
            pre=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pre->next=NULL;
        ListNode* l=mergeList(head);
        ListNode* r=mergeList(slow);
        return merge(l,r);
    }
    ListNode* merge(ListNode *l,ListNode *r){
        if(!l) return r;
        if(!r) return l;
        if(l->val<=r->val){
            l->next=merge(l->next,r);
            return l;
        }else{
            r->next=merge(l,r->next);
            return r;
        }
    }
};
```