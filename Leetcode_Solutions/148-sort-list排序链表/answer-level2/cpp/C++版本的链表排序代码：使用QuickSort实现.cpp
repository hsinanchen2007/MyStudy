# C++版本的链表排序代码：使用QuickSort实现
```
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		quickSort(head, nullptr);
		return head;
	}

	void quickSort(ListNode* head, ListNode* tail) {
		if (head == tail || head->next == nullptr) {
			return;
		}

		ListNode* mid = partition(head, tail);

		quickSort(head, mid);
		quickSort(mid->next, tail);
	}

	ListNode* partition(ListNode* head, ListNode * tail) {

		int pivot = head->val;
		ListNode* s = head;
		ListNode* cur = head->next;
		while (cur != nullptr && cur != tail)
		{
			if (cur->val < pivot) {
				s = s->next;
				swap(s, cur);
			}
			cur = cur->next;
		}
		swap(s, head);
		return s;
	}


	void swap(ListNode* a, ListNode* b) {
		int temp = a->val;
		a->val = b->val;
		b->val = temp;
	}

};
```

