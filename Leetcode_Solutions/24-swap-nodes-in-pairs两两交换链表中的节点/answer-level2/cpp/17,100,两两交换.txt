### 解题思路
一趟循环即可，仅考虑以下情况：
当前节点是否为头节点，是否余留一个节点

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
	ListNode* swapPairs(ListNode* head) {
		ListNode *p = head;
		while (p != NULL)
		{
			//处理头节点的情况,交换
			if (p == head)
			{
				if (p->next != NULL)
				{
					head = p->next;
					p->next = p->next->next;
					head->next = p;
					continue;
				}
				//只有一个节点
				return head;
			}
			//处理余留一个节点的情况
			if (p->next == NULL || p->next->next == NULL)
				return head;
			//非头节点的情况
			ListNode *temp1 = p->next, *temp2 = p->next->next;
			temp1->next = temp2->next;
			temp2->next = temp1;
			p->next = temp2;
			p = p->next->next;


		}

		return head;

	}
};

```