### 解题思路
执行用时 :2180 ms, 在所有 C++ 提交中击败了5.35% 的用户
内存消耗 :18.8 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode* removeDuplicateNodes(ListNode* head){
    	if(!head || !head->next) return head;
    	ListNode* head_no_dup = new ListNode(head->val);
    	ListNode* head_no_dup_bak = head_no_dup;
    	set<int> s_l;
    	s_l.insert(head->val);
    	head = head->next;
    	while(head){
    		auto ind = std::find(s_l.begin(), s_l.end(), head->val);
    		if(ind == s_l.end()){
    			s_l.insert(head->val);
    			head_no_dup_bak->next = new ListNode(head->val);
    			head_no_dup_bak = head_no_dup_bak->next;
    		}
    		head = head->next;
    	}
    	return head_no_dup;
    }
};
```