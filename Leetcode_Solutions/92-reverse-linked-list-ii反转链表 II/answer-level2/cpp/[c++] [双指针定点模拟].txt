### 解题思路
把位置m的结点用cur标定，以及结点m的前一个结点用pre标定。

### 代码

```cpp
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* dummy = new ListNode(-1);
		ListNode* pre = dummy;
		dummy->next = head;
		for (int i = 0; i < m - 1; i++) {
			pre = pre->next;
		}
		ListNode* cur = pre->next;
		for (int i = m; i < n; i++) {
			ListNode* t = cur->next;
			cur->next = t->next;
			t->next = pre->next;
			pre->next = t;
		}
		return dummy->next;
	}
};
```