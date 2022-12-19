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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* d=new ListNode(0);
        d->next=head;
        ListNode* first=d;
        ListNode* sec=d;
        while(1){
            for(int j=0;j<k-1&&sec->next!=NULL;j++){
                sec=sec->next;
            }
            if(sec->next==NULL) break;
            first->next=reverse(first->next,sec->next,k);
            
            for(int j=0;j<k;j++){
                first=first->next;
            }
            sec=first;
        }

        return d->next;
    }
    ListNode* reverse(ListNode* head, ListNode* end,int k){
        ListNode* tem;
        ListNode* end2;
        while(k>1){
            k--;
            end2=end->next;
            tem=head->next;
            end->next=head;
            head->next=end2;
            head=tem;
            

        }
        return head;
    }

};
```
