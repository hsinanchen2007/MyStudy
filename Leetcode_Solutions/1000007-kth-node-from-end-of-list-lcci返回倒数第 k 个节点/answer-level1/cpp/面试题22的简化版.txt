### 解题思路
执行用时 :4 ms, 在所有 C++ 提交中击败了73.14% 的用户
内存消耗 :12.9 MB, 在所有 C++ 提交中击败了100.00%的用户

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
	ListNode* ReverseList(ListNode* head){
		if(!head || !head->next) return head;
		ListNode* head_bak = new ListNode(head->val);
		head = head->next;
		while(head){
			ListNode* new_node = new ListNode(head->val);
			new_node->next = head_bak;
			head_bak = new_node;
			head = head->next;
		}
		return head_bak;
	}
    int kthToLast(ListNode* head, int k) {
    	ListNode* head_rev = ReverseList(head);
    	int ind = 1;
    	ListNode* head_rev_bak = head_rev;

    	while(ind < k){
    		if(!head_rev_bak) break;
    		head_rev_bak = head_rev_bak->next;
    		ind++;
    	}
    	return head_rev_bak->val;
    }
};
```