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
        if(head==nullptr||head->next==nullptr)
            return head;
        int i=1; 
        int o=1;
        ListNode*cur=head;
        ListNode*temp;    
        while(cur->next)
        {
            cur=cur->next;
            ++o;
        }
        int l=k%o;
        while(i<=l)
        {
            temp=head;
            cur=head;
            while(cur->next->next)
            {
                cur=cur->next;
            }
            cur->next->next=head;
            head=cur->next;
            cur->next=nullptr;
            i++;
        }
         return head;
    }
};