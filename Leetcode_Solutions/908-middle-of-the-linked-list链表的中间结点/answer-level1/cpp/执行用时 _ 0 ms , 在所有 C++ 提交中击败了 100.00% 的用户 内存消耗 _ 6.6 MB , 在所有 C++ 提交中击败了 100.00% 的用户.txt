### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		
		ListNode* slow = head;
		ListNode* fast = head;
		
		while (fast!=NULL&&fast->next!=NULL) {
			slow = slow->next;
		
			fast = fast->next;
		
			fast = fast->next;
		
		}
		

		return slow;
	}
};
```