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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
    	ListNode* odd_even_list = new ListNode(head->val);
    	ListNode* odd_even_list_bak = odd_even_list;
    	ListNode* head_bak_even = head;
    	ListNode* head_bak_odd = head->next;
    	while(head_bak_even){
    		if(head_bak_even->next && head_bak_even->next->next){
    			ListNode* new_node = new ListNode(head_bak_even->next->next->val);
        		odd_even_list_bak->next = new_node;
        		odd_even_list_bak = odd_even_list_bak->next;
        		head_bak_even = head_bak_even->next->next;
    		}else{
    			break;
    		}
    	}
    	odd_even_list_bak = odd_even_list;
    	while(odd_even_list_bak->next){
    		odd_even_list_bak = odd_even_list_bak->next;
    	}
    	while(head_bak_odd){
    		ListNode* new_node = new ListNode(head_bak_odd->val);
    		odd_even_list_bak->next = new_node;
    		odd_even_list_bak = odd_even_list_bak->next;
            if(!head_bak_odd->next || ! head_bak_odd->next->next) break;
    		head_bak_odd = head_bak_odd->next->next;
    	}
    	return odd_even_list;
    }
};
```