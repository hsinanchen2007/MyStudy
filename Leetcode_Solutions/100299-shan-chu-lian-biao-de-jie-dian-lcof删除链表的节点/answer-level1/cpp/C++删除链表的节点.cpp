### 解题思路
主要分了4种情况进行分析
1、链表为空，直接返回
2、链表只有一个节点时，如果该节点值和其相等，或者不等
3、链表的第一个节点和该节点值相等的处理
4、链表中的某个值和该节点值相等
### 代码

```cpp
class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		if (head == nullptr) return nullptr;//head为空
		ListNode* cur=head;
		ListNode* prev = nullptr;
		if (cur->next==nullptr)//只有一个节点
		{
			if (cur->val==val)//该节点值与所给值相等
			{
				return nullptr;
			}
			else//不等
			{
				return head;
			}
		}
		//如果第一个节点和其相等
		if (cur->val==val)
		{
			return head->next;
		}
		while (cur)
		{
			if (cur->val==val)//值相等
			{
				prev->next=cur->next;
				return head;
			}
			prev = cur;
			cur = cur->next;
		}
		return head;
	}
};
```