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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         ListNode* p=head;
        ListNode* q=head;
        ListNode* m=head->next;
        for(int i=0;i<n;i++)
        {
            if(q->next)
            q=q->next;
            else 
            return head->next;
        }
        while(q->next){
            p=p->next;
            q=q->next;
            m=m->next;
        }
        p->next=m->next;
        
        return head;
    }
};