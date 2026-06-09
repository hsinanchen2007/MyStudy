### 解题思路
此处撰写解题思路
![LeetCode-148.png](https://pic.leetcode-cn.com/f7cdcc90515a9a7f902ee4f965abc85940282a98a8cd6e8b1e5221386b7c7908-LeetCode-148.png)

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
    ListNode* sortList(ListNode* head) {
    	if(!head) return NULL;
    	if(!head->next) return head;
    	vector<int> vec;
    	while(head){
    		vec.push_back(head->val);
    		head = head->next;
    	}
    	std::sort(vec.begin(), vec.end());
    	ListNode* head_sorted = new ListNode(vec[0]);
    	ListNode* head_sorted_bak = head_sorted;
    	for(size_t i=1;i<vec.size();++i){
    		head_sorted_bak->next = new ListNode(vec[i]);
    		head_sorted_bak = head_sorted_bak->next;
    	}
    	//for debug
    	//UnitTest ut;
    	//ut.TraverseListNode(head_sorted);
    	return head_sorted;
    }
};
