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
    ListNode* reverseList(ListNode* head) {
		if(!head) return head;
        ListNode* heada=new ListNode(0),*res=heada;
		stack<ListNode*> s;
		while(head){s.push(head);head=head->next;}
		while(!s.empty()){
			heada->next=s.top();
			s.pop();
			heada=heada->next;
		}
        heada->next=NULL;
		return res->next;
    }
};