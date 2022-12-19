### 解题思路
将链表分为三部分，第一部分是待反转前的部分，第二部分等待反转，第三部分是剩余部分；
需要做的事情就是，将第一部分的尾指向反转后的第二部分，将第二部分的尾部指向第三部分。
时间O(n)空间O(1)
### 代码

```cpp
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		int index = 0;
		ListNode* pre = nullptr;
		ListNode* tail = nullptr;
		ListNode* hea = nullptr;
		ListNode* latter = nullptr;
		ListNode* node = head;
		ListNode* front = nullptr;
		ListNode* next = nullptr;
		while (node != nullptr) {
			index++;
			if (index == m - 1) {
				pre = node;
				node = node->next;
				continue;
			}
			else if (index == m) {
				tail = node;
			}
			else if (index == n) {
				hea = node;
				latter = node->next;
				hea->next = front;
				break;
			}
			if (index >= m && index < n) {
				next = node->next;
				node->next = front;
				front = node;
				node = next;
			}
			else {
				node = node->next;
			}
		}
		if (pre != nullptr) {
			pre->next = hea;
		}
		else {
			head = hea;
		}
		tail->next = latter;
		return head;
	}
};
```