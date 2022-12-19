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
 #include <stdlib.h>
class Solution {
public:
int sum = 0;
ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL&&l2 == NULL&&sum == 0)return NULL;
	l1 = l1 != NULL ? (c += l1->val, l1->next) : l1;//
	l2 = l2 != NULL ? (c += l2->val, l2->next) : l2;
	ListNode *cur = new ListNode(sum % 10);
	sum = sum / 10;
	cur->next = addTwoNumbers(l1, l2);
	return cur;
}
};
```