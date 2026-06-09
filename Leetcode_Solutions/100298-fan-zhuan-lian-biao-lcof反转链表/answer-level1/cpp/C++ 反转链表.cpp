### 解题思路
同06.从尾到头打印链表

### 代码

```cpp
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev, * cur, * temp;//prev指向当前结点的前驱结点,cur指向当前结点,temp存储当前结点的下一节点
		prev = NULL;
		cur = head;
		while (cur)
		{
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		return prev;
	}
};
```