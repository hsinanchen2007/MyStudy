```C++ []
class Solution {
public:
	ListNode* removeDuplicateNodes(ListNode* head) {
		unordered_set<int> s;
		ListNode* h1 = head, *h2 = head;
		if (h1) {
			s.insert(h1->val);
			h1 = h1->next;
		}
		while (h1) {
			if (s.find(h1->val) == s.end()) {
				s.insert(h1->val);
				h1 = h1->next;
				h2 = h2->next;
			}
			else {
				h2->next = h1->next;
				h1 = h2->next;
			}
		}
		return head;
	}
};
```
