### 解题思路
此处撰写解题思路

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
    ListNode* middleNode(ListNode* head) {
		if(head==NULL)
			return  NULL;
		ListNode* kuai=head->next;
		ListNode* man=head;
		while(true)
		{
			if(kuai==NULL)
				return man;
			else if(kuai->next==NULL)
				return man->next;
			kuai=kuai->next->next;
			man=man->next;
		}
    }
};
```