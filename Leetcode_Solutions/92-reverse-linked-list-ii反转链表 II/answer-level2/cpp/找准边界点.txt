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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
		if(!head || !head->next || (m == n)) return head;
		int start = m;
		int end = n;
		int ind = 1;
		ListNode* head_bak = head;
		ListNode* list_header_up_bound = head;
		while(ind < start){
			if(ind == (start - 1)){
				list_header_up_bound = head_bak;
			}
			head_bak = head_bak->next;
			ind++;
		}
		ListNode* list_mid = new ListNode(head_bak->val);
		ListNode* list_mid_ini_node = list_mid;//saved for attaching head_bak (tail)

		head_bak = head_bak->next;
		while(head_bak && (ind < end)){
			ListNode* new_node = new ListNode(head_bak->val);
			new_node->next = list_mid;
			list_mid = new_node;
			head_bak = head_bak->next;
			ind++;
		}
		list_header_up_bound->next = list_mid;
		list_mid_ini_node->next = head_bak;

		return (start == 1) ? list_mid : head;
    }
};
```