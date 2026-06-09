### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了96.82% 的用户
内存消耗 :9.3 MB, 在所有 C++ 提交中击败了15.18%的用户

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
    	ListNode* head_bak = head;
    	while(head_bak && head_bak->next){
    		if(head_bak->val == head_bak->next->val){
    			head_bak->next = head_bak->next->next;
    		}else{
    			head_bak = head_bak->next;
    		}
    	}
    	return head;
    }
};
```