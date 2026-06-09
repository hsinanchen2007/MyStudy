### 解题思路
执行用时 :96 ms, 在所有 C++ 提交中击败了17.19% 的用户
内存消耗 :17 MB, 在所有 C++ 提交中击败了100.00%的用户

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(!headA || !headB) return NULL;
    	ListNode* headA_bak = headA;
    	ListNode* headB_bak = headB;
    	while(headA != headB){
    		if(headA){
    			headA = headA->next;
    		}else{
    			headA = headB_bak;
    		}

    		if(headB){
    			headB = headB->next;
    		}else{
    			headB = headA_bak;
    		}
    	}
    	return headA;
    }
};
```