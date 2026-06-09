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
//	//1) 暴力法: 取出A中的每个节点，在B中检索该节点. 时间复杂度O(MN)
//	ListNode* GetIntersectNode(ListNode* headB, ListNode* target){
//		while(headB){
//			if(target == headB){
//				return target;
//			}
//			headB = headB->next;
//		}
//		return NULL;
//	}
//    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//    	while(headA){
//    		ListNode* intersect_node = GetIntersectNode(headB, headA);
//    		if(intersect_node) return intersect_node;
//    		headA = headA->next;
//    	}
//    	return NULL;
//    }
    //2) 先将head*存入vector，时间复杂度是O(M);再在vector中查找headB*的每个节点，复杂度是N*O(1)
    //总共的时间复杂度是O(M+N)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	vector<ListNode*> vec_headA;
    	while(headA){
    		vec_headA.push_back(headA);
    		headA = headA->next;
    	}
    	while(headB){
    		auto ind = std::find(vec_headA.begin(), vec_headA.end(), headB);
    		if(ind != vec_headA.end()) return headB;
    		headB = headB->next;
    	}
    	return NULL;
    }
};
```