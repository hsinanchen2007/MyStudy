执行用时 :20 ms, 在所有 C++ 提交中击败了92.44%的用户
内存消耗 :15.9 MB,在所有C++ 提交中击败了5.04%的用户
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
class Solution 
{
public:
	ListNode* removeElements(ListNode* head, int val) 
	{
		ListNode* p, * q;
       // if (head == NULL) return head;
        while ((head!=NULL)&&(head->val == val))
			head = head->next;
		if (head == NULL) return head;
		p = head;
		q = head->next;
		while (q)
		{
			if (q->val == val)
			{
				p->next = q->next;
				q = p->next;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		return head;
	}
};
```