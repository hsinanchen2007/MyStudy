### 解题思路
执行用时 :52 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :16.9 MB, 在所有 C++ 提交中击败了100.00%的用户

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
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
		if(!headA || !headB) return NULL;
		ListNode* headA_bak = headA;
		ListNode* headB_bak = headB;
		while(headA != headB){
			if(!headA){
				headA = headB_bak;
			}else{
				headA = headA->next;
			}
			if(!headB){
				headB = headA_bak;
			}else{
				headB = headB->next;
			}
		}
		return headA;
	}
    /*ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	vector<ListNode*> v_A;
    	while(headA){
    		v_A.push_back(headA);
    		headA = headA->next;
    	}
    	while(headB){
    		auto ind = std::find(v_A.begin(), v_A.end(), headB);
    		if(ind != v_A.end()) return headB;
    		headB = headB->next;
    	}
    	return NULL;
    }*/
};
```