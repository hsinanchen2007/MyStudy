### 解题思路
C++,算法初学者，就使用最暴力的解法，分类讨论。
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
		int carry = 0;
		ListNode vHead(0);
		ListNode* p = &vHead;
		ListNode* NewNode;
		do {
			NewNode = new ListNode(0);
			p->next = NewNode;
			p = p->next;
			if (l1&&l2) {
				p->val = ((l1->val + l2->val) % 10 + carry)%10;
				if ((l1->val + l2->val >= 10) || ((l1->val + l2->val) % 10 + carry) >= 10)
					carry = 1;
				//这个方程包含俩种产生进位情况，一种是l1->val和l2->val相加产生进位
				//产生进位，这时靠方程z=(l1->val + l2->val) % 10 + carry就能够解决
				//另一种情况是l1->val与l2->val相加不产生进位，但是再加上一位的进位
				//会产生进位，例：4+5+carry，这时就要使方程z%10得到当前位的值
				else carry = 0;
				l1 = l1->next;
				l2 = l2->next;
			}
			else if (l1) {
				p->val = (l1->val + carry) % 10;
				if (l1->val + carry >= 10)
					carry = 1;
				else carry = 0;
				l1 = l1->next;
			}//考虑到俩个数不一定有相同位如：123+1234
			else if (l2) {
				p->val = (l2->val + carry) % 10;
				if (l2->val + carry >= 10)
					carry = 1;
				else carry = 0;
				l2 = l2->next;
			}//同上
			else {
				p->val = carry;
				carry = 0;
			}//考虑最高位相加会产生进位的情况例如：5+5=10
			
		} while (l1 || (carry == 1) || l2);
		return vHead.next;
    }
};
```