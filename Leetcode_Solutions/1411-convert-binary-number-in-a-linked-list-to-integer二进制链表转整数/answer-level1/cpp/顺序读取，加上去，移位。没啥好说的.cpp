```C++ []
class Solution {
public:
	int getDecimalValue(ListNode* head) {
		int dec = 0;
		while (head) {
			dec <<= 1;
			dec += head->val;
			head = head->next;
		}
		return dec;
	}
};
```
