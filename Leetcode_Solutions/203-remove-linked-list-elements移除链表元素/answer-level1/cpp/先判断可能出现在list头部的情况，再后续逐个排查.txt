### 解题思路
执行用时 :16 ms, 在所有 C++ 提交中击败了99.03% 的用户
内存消耗 :11 MB, 在所有 C++ 提交中击败了40.72%的用户

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
    ListNode* removeElements(ListNode* head, int val) {
    	if(!head) return NULL;
    	while(head->val == val){
    		head = head->next;
    		if(!head) return head;
    	}
    	ListNode* head_bak = head;
    	while(head_bak->next){
    		if(head_bak->next->val == val){
    			if(!head_bak->next->next) head_bak->next = NULL;
    			else head_bak->next = head_bak->next->next;
    		}else{
    			head_bak = head_bak->next;
    			if(!head_bak) return head;
    		}
    	}
    	return head;
    }
};
```