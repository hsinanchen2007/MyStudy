```C++ []
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		stack<int> s;
		int count = 0;
		ListNode* cur = head;
		while (cur) {
			count++;
			cur = cur->next;
		}
		cur = head;
		for (int i = 0; i < count / 2; i++) {
			s.push(cur->val);
			cur = cur->next;
		}
		if (count % 2)
			cur = cur->next;
		while (cur) {
			if (s.top() != cur->val)
				return false;
			s.pop();
			cur = cur->next;
		}
		return true;
	}
};
```
