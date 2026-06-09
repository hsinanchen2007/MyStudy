### 解题思路
这个题按照普通加法的方式模拟就好了。链表中每一个数字是倒序的，所以最前面的是最低位，普通加法的做法也就是最低为直接相加，一次到高位。所以同时遍历两个链表，从低位开始，一个一个往后算就好了。

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
		ListNode* temp = new ListNode(0);
		ListNode* t = temp; int carry = 0;
		while (l1||l2)
		{
			
			if (!l1)
			{
				temp->next = new ListNode((l2->val+carry)%10);
				carry = (l2->val + carry) / 10;
				l2 = l2->next;
			}
			else if (!l2)
			{
				temp->next = new ListNode((l1->val+carry)%10);
				carry = (l1->val + carry) / 10;
				l1 = l1->next;
			}
			else
			{
				temp->next = new ListNode((l1->val + l2->val+carry) % 10);
				carry = (l1->val + l2->val + carry) / 10;
				l1 = l1->next;
				l2 = l2->next;
			}
			temp = temp->next;
		}
        if (carry == 1) temp->next = new ListNode(1);
		return t->next;
		delete t;
	}
};
```