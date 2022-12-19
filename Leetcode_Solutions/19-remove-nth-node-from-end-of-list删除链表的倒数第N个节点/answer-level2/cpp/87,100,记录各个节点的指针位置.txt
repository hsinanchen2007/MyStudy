### 解题思路
一趟扫描的话，额外使用一个哈希表用来记录(各节点的位置，单链表中各个节点的指针)，
扫描完之后直接读取指针删除就完事了

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

		ListNode *p = head;
		map<int, ListNode*> i2lmap;
		int pos = 0;
		while (p != NULL)
		{
			i2lmap[pos] = p;
			pos++;
			p = p->next;
		}
		if (n == i2lmap.size())
			return head->next;
		//删除倒数第n个节点，得到倒数第n+1个节点的指针
		p = (i2lmap.find(i2lmap.size() - n - 1))->second;
		p->next = p->next->next;

		return head;
	}
};
```