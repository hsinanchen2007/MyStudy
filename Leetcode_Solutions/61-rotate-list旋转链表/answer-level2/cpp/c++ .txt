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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL||k==0)return head;
        int len=1;
        auto tail=head;
        while(tail->next){
            tail=tail->next;
            ++len;
        }
        k%=len;
        if(k==0)return head;
        auto right=head;
        for(int i=0;i<k;++i)right=right->next;
        auto left=head;
        while(right->next){
            right=right->next;
            left=left->next;
        }
        auto tmp=left->next;
        left->next=NULL;
        tail->next=head;
        return tmp;
    }
};
```
