### 解题思路
执行用时 :8 ms, 在所有 C++ 提交中击败了54.45% 的用户
内存消耗 :8.9 MB, 在所有 C++ 提交中击败了5.10%的用户

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
	//234
	ListNode* GetReverseListNode(ListNode* head){
		ListNode* rev_list = new ListNode(head->val);
		ListNode* head_bak = head->next;
		while(head_bak != NULL){
			ListNode* new_node = new ListNode(head_bak->val);
			new_node->next = rev_list;
			rev_list = new_node;
			head_bak = head_bak->next;
		}
//		cout << "reversed list is ";
//		UnitTest ut;
//		ut.TraverseListNode(rev_list);
		return rev_list;
	}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next) return NULL;
    	// //for debug
    	//UnitTest ut;
    	//for debug
//    	ut.TraverseListNode(head_bak);
    	ListNode* head_rev = GetReverseListNode(head);
    	ListNode* head_rev_bak = head_rev;
    	int ind_rev = 1;
    	if(n==1){
    		//head_rev_bak = head_rev_bak->next;
            head_rev = head_rev->next;
    	}else if(n==2){
    		head_rev_bak->next = head_rev_bak->next->next;
    	}else{
    		while(ind_rev < (n-1)){
    			head_rev_bak = head_rev_bak->next;
                ++ind_rev;
    		}
    		head_rev_bak->next = head_rev_bak->next->next;
    	}
//    	//for debug
//    	cout << "After del, head_rev is" << endl;
//    	ut.TraverseListNode(head_rev);
    	head = GetReverseListNode(head_rev);
//    	//for debug
//    	cout << "And head is " << endl;
//    	ut.TraverseListNode(head);
    	//for debug
//    	ut.TraverseListNode(head_rev);
    	return head;
    }
};
```