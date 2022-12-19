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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *head=new ListNode(-1),*p,*q,*r;
        r=head;
        p=l1;
        q=l2;
        while(p&&q)
        {
            if(p->val>q->val)
            {
                r->next=q;
                q=q->next;
                r=r->next;
            }
            else
            {
                r->next=p;
                p=p->next;
                r=r->next;
            }
        }
        if(!p)
            r->next=q;
        else
            r->next=p;
        return head->next;       
    }
};