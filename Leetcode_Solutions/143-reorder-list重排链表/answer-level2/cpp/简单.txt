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
    void reorderList(ListNode* head) {
        if(!head) return;
    	size_t list_len = 0;
    	ListNode* head_bak = head;
    	while(head_bak){
    		++list_len;
    		head_bak = head_bak->next;
    	}
//    	//for debug
//    	UnitTest ut;
//    	cout << "\nBefore Process, head = ";
//    	ut.TraverseListNode(head);

    	ListNode* head_rev = GetReverseListNode(head);
    	ListNode* head_reorder = head;
    	ListNode* head_reorder_bak = head_reorder;
    	head = head->next;
    	size_t operations = 0;

    	while(operations < list_len/2){
    		head_reorder_bak->next = new ListNode(head_rev->val);
    		head_reorder_bak = head_reorder_bak->next;

    		if(operations == (list_len/2-1)){
    			if(list_len % 2){
    	    		head_reorder_bak->next = new ListNode(head->val);
    	    		head_reorder_bak = head_reorder_bak->next;
    			}
    		}else{
	    		head_reorder_bak->next = new ListNode(head->val);
	    		head_reorder_bak = head_reorder_bak->next;
    		}

    		head = head->next;
    		head_rev = head_rev->next;
    		operations++;

//        	cout << "After operations = " << operations << ", head_reorder = ";
//        	ut.TraverseListNode(head_reorder);
//        	cout << "head = ";
//        	ut.TraverseListNode(head);
//        	cout << "head_rev = ";
//        	ut.TraverseListNode(head_rev);
    	}
    	head = head_reorder;
//    	cout << "After process， head = ";
//    	ut.TraverseListNode(head);
    }
};
```