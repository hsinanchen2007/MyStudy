```
class Solution {

	void swap(ListNode* a, ListNode* b) {
		int tmp = a->val;
		a->val = b->val;
		b->val = tmp;
	}

	ListNode* partition(ListNode* head, ListNode* l, ListNode* r) {
		if (l == r) return l;

		ListNode *curr = l;
		int pvoit = l->val;
		ListNode *less=new ListNode(0), *pre_less=nullptr;
		less->next = l;
		while (curr != r->next) {
			if (curr->val <= pvoit) {
				swap(curr, less->next);
				pre_less = less;
				less = less->next;
			}
			curr = curr->next;
		}
		swap(less, l);
		return pre_less;
	}

	void quicSort(ListNode* head, ListNode* l, ListNode* r) {
		if (l == r) return;
		ListNode* pre_curr = partition(head, l, r);
		if (pre_curr->next != l && pre_curr != l)
			quicSort(head, l, pre_curr);
		if (pre_curr->next != r && pre_curr->next->next && pre_curr->next->next != r)
			quicSort(head, pre_curr->next->next, r);
	}

public:
	ListNode* sortList(ListNode* head) {

		if (!head) return head;

		ListNode *begin = head, *end=nullptr;
		while (head) {
			end = head;
			head = head->next;
		}
		quicSort(begin, begin, end);
		return begin;
	}
};
```
