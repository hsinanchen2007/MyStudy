### 解题思路
感觉想的太多，步骤太繁琐，但总归是做出来了，希望各位大佬能够多加指正。
首先，主要两种大情况：三种情况：1、两个链表长度相同。2、l1更长。3、l2更长。
我先通过一个for循环找到，处理到最短链表的最后一个节点。
然后开始分上述三种情况讨论。大致就是这样，如果有大佬愿意指正，可以自行看下面的代码。
总体来说，很不满意，感觉思路混乱。


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
       ListNode* temp1 = l1;
		ListNode* temp2 = l2;
		int t;
		bool carry = false;
		for (; temp1->next&&temp2->next; temp1 = temp1->next, temp2 = temp2->next)
		{
			t = temp1->val + temp2->val + carry;
			if (t >= 10)
			{
				carry = true;
			}
			else
				carry = false;
			temp1->val = t % 10;

		}
		if (!temp1->next && !temp2->next)
		{
			t = temp1->val + temp2->val + carry;
			temp1->val = t % 10;
			temp1->val = t % 10;
			if (t >= 10)
			{
				
				temp1->next = new ListNode(1);
			}
			return l1;
		}
		if (temp1->next)
		{
			t = temp1->val + temp2->val + carry;
			if (t < 10)
			{
				temp1->val = t;
				return l1;
			}
			for (; temp1->next; temp1 = temp1->next)
			{
				temp1->val = t % 10;
				if (t >= 10)
					carry = true;
				else
					carry = false;
				t = temp1->next->val + carry;
				temp1->next->val = t;
			}
			if (t >= 10)
			{
				temp1->val = t % 10;
				temp1->next = new ListNode(1);
			}
			return l1;

		}
		if (temp2->next)
		{
			t = temp1->val + temp2->val + carry;
			temp1->next = temp2->next;
			if (t < 10)
			{
				temp1->val = t;
				return l1;
			}
			for (; temp1->next; temp1 = temp1->next)
			{
				temp1->val = t % 10;
				if (t >= 10)
					carry = true;
				else
					carry = false;
				t = temp1->next->val + carry;
				temp1->next->val = t;
			}
			if (t >= 10)
			{
				temp1->val = t % 10;
				temp1->next = new ListNode(1);
			}
			
		}
		return l1;

    }

};
```