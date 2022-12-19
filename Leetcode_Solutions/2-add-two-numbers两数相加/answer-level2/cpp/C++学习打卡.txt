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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int curValue = 0, carryOn = 0;
		ListNode *ans = new ListNode(0), *cur = ans;
		while (l1 != nullptr && l2 != nullptr) {
			int sum = l1->val + l2->val + carryOn;
			carryOn = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;

			l1 = l1->next;
			l2 = l2->next;
		}

		while (l1 != nullptr) {
			int sum = l1->val + carryOn;
			carryOn = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;

			l1 = l1->next;
		}
		while (l2 != nullptr) {
			int sum = l2->val + carryOn;
			carryOn = sum / 10;
			cur->next = new ListNode(sum % 10);
			cur = cur->next;

			l2 = l2->next;
		}
		if (carryOn != 0) {
			cur->next = new ListNode(carryOn);
			cur = cur->next;
		}
		return ans->next;
	}
};
```