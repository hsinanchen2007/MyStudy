### 解题思路
本题快慢指针不需要针对链表长度是偶数还是奇数进行特别处理。

![image.png](https://pic.leetcode-cn.com/43494c599f9c2b5ed06457a8e048ac51ad421dbbe778736867440bbeaa24888d-image.png)

### 代码

```
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* newhead = slow->next;
		slow->next = NULL;	//新链表尾部置空
		newhead = reverse(newhead);	//链表反转
		while (newhead) {
			ListNode* temp = newhead->next;
			newhead->next = head->next;
			head->next = newhead;
			head = newhead->next;
			newhead = temp;
		}
	}
	ListNode* reverse(ListNode* head) {	//链表反转标准写法
		ListNode* new_head = NULL;
		while (head) {
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};
```
