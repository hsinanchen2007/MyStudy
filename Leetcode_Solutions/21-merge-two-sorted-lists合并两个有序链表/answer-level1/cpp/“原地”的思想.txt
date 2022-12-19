### 解题思路
create the merged list on-the-fly, that is, compare each value of l1* and l2*, and create the new node then. No need using a vector to hold all the values, and then sort.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	if(l1 == NULL) return l2;
    	else if (l2 == NULL) return l1;

    	ListNode* merged_list = new ListNode(0);
    	ListNode* merged_list_bak = merged_list;
    	while(l1 != NULL && l2 != NULL){
    		merged_list_bak->val = (l1->val < l2->val)? l1->val : l2->val;
    		if(l1->val < l2->val){
    			if(l1->next != NULL){
            		merged_list_bak->next = new ListNode(0);
            		merged_list_bak = merged_list_bak->next;
    			}
    			l1 = l1->next;
    		}else{
    			if(l2->next != NULL){
            		merged_list_bak->next = new ListNode(0);
            		merged_list_bak = merged_list_bak->next;
    			}
    			l2 = l2->next;
    		}
    	}
    	if(l1 == NULL && l2 == NULL) return merged_list;
    	else if(l1 != NULL){
    		merged_list_bak->next = l1;
    	}
    	else{
    		merged_list_bak->next = l2;
    	}
    	return merged_list;
    }
    /*ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* merged_list = l1;
    	ListNode* merged_list_bak = l1;
        if(l1 == NULL) return l2;
    	else if (l2 == NULL) return l1;
    	while(merged_list_bak->next != NULL){
    		merged_list_bak = merged_list_bak->next;
    	}
    	merged_list_bak->next = l2;

    	//sort
    	vector<int> vec_sort;
    	merged_list_bak = merged_list;
    	while(merged_list_bak != NULL){
    		vec_sort.push_back(merged_list_bak->val);
    		merged_list_bak = merged_list_bak->next;
    	}
    	sort(vec_sort.begin(), vec_sort.end());

    	merged_list_bak = merged_list;
    	int ind = 0;
    	while(merged_list_bak != NULL){
    		merged_list_bak->val = vec_sort[ind++];
    		merged_list_bak = merged_list_bak->next;
    	}
    	return merged_list;
    }*/
};
```