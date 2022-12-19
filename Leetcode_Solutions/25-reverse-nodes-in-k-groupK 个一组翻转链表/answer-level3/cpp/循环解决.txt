首先找到待翻转的区间,然后翻转.
```
class Solution {
    ListNode *reverse(ListNode *begin, ListNode *end){
		ListNode *p, *t;
		for(p=begin, begin=end; p!=end; p=t){
			t = p->next;
			p->next = begin;
			begin = p;
		}
		return begin;       // tail link to end
	}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k<2) return head;
		ListNode H(-1), *tail, *end;
		for(H.next=head, tail=head=&H; (end=head=head->next);){
			for(int i=0; ++i<k && end; end=end->next);
			if (end==NULL) break;	// not enough k nodes
			tail->next = reverse(head,end->next);
			tail = head;		// tail->next auto link to next
		}
		return H.next;
    }
};
```
