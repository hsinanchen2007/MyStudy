


#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode *q = new ListNode(0);
		ListNode *p = new ListNode(0);
		q = head;
		p = head;
		while (head->next!= NULL) {
	       for (int i = 0; i < n; i++) {
			head = head->next;
		   }
		   if (head == NULL) {
			   if (q->next == NULL) { return NULL; }
			   return p->next;
		   }
		   if (head->next != NULL) {
		   		head = p->next;
		        p = p->next;
		   }
		}
		if (q->next == NULL) { return NULL; }
		p->next = p->next->next;
		return q;
	}
};