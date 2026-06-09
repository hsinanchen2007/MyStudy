### 解题思路
/*
//在head前加上一个新结点（哑结点）用于处理极端情况，如删除头节点
//使用（快慢）双指针来保证当fast到达尾部的时候，low指向需要删除结点的前一个结点
*/

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		ListNode *fast = newHead, *low = newHead;
		for (int i = 0; i < n; i++) { fast = fast->next; }
		while (fast->next != NULL) {
			fast = fast->next;
			low = low->next;
		}
		ListNode *temp = low->next;
		low->next = temp->next;
		temp->next = NULL;
		delete temp;

		head = newHead->next;
		newHead->next = NULL;
		delete newHead;
		return head;
	}
};
```