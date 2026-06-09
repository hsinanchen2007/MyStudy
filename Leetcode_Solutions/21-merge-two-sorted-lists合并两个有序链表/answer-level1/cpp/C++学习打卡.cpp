### 解题思路
此处撰写解题思路

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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0), *ans = head;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				head->next = l1;
				head = head->next;
				l1 = l1->next;
			}
			else {
				head->next = l2;
				head = head->next;
				l2 = l2->next;
			}
		}
		if (l1 != nullptr) { head->next = l1; }
		if (l2 != nullptr) { head->next = l2; }

		ListNode *temp = ans;
		ans = ans->next;
		temp->next = nullptr;
		delete temp;
		return ans;
	}
};
```