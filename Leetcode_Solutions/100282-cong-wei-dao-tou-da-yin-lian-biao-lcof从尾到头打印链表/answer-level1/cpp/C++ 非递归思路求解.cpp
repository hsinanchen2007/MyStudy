### 解题思路
非递归思路解反转链表

### 代码

```cpp
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		ListNode *prev, *cur,*temp;//prev指向当前结点的前驱结点,cur指向当前结点,temp存储当前结点的下一节点
		prev = NULL;//prev初始为null
		cur = head;//cur初始指向头结点
		while (cur)
		{
			temp = cur->next;
			cur->next = prev;
			prev = cur;
			cur = temp;
		}
		head = prev;
		vector<int> list;
		while (head)
		{
			list.push_back(head->val);
			head = head->next;
		}
		return list;
	}
};
```