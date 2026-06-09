### 解题思路

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
    ListNode* deleteNode(ListNode* head, int val) {
    	if(val == head->val) return head->next;
    	ListNode* head_bak = head;
    	while(head_bak->next){
    		if(val == head_bak->next->val){
    			head_bak->next = head_bak->next->next;
    			return head;
    		}
    		//TraverseListNode(head);
    		head_bak = head_bak->next;
    	}
    	return head;
    }
};
```