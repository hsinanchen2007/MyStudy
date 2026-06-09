### 解题思路
采用两个指针，快指针指向长链表，慢指针指向短链表

### 代码

```cpp
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		ListNode* l1 = headA, * l2 = headB;
		//求l1的长度
		int countL1 = 0;
		while (l1 != nullptr)
		{
			countL1++;
			l1 = l1->next;
		}
		//求l2的长度
		int countL2 = 0;
		while (l2 != nullptr)
		{
			countL2++;
			l2 = l2->next;
		}
		//求l1和l2的差值,l1指向长链表，l2指向短链表
		l1 = headA;
		l2 = headB;
		int diff = countL1 - countL2;
		//判断两者谁更长
		if (countL1 < countL2)
		{
			l1 = headB;
			l2 = headA;
			diff = countL2 - countL1;
		}
		//l1先走diff步
		while (diff--)
		{
			l1 = l1->next;
		}
		//找共同节点
		while (l1 != nullptr && l2 != nullptr && l1 != l2)
		{
			l1 = l1->next;
			l2 = l2->next;
		}
		return l1;
	}
};
```