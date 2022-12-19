### 解题思路
两遍遍历

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
	ListNode* middleNode(ListNode* head) {
		int nodeCount = 0;
		ListNode *cur = head;
		while (cur != nullptr) {
			nodeCount++; 
			cur = cur->next;
		}
		nodeCount = nodeCount / 2 + 1;
		cur = head;
		for (int i = 1; i < nodeCount; i++) {
			cur = cur->next;
		}
		return cur;
	}
};
```