### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int count = 0;
		ListNode *p = head;
		while (head!=NULL) {
			count++;
			head = head->next;
		}

		int x = count-n;
		if (x == 0) return p->next;

		ListNode* pre = NULL;
		ListNode* pp = p;

		for (int i = 1; i <= x;i++) {
			pre = pp;
			pp = pp->next;
		}
		pre->next = pp->next;
		return p;

	}
};
```