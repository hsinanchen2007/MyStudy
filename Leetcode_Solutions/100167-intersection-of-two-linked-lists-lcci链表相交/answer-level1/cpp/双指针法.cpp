### 解题思路
双指针法

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

    	while(headA != headB)
        {
    		if(headA != NULL)
            {
    			headA = headA->next;
    		}
            else
            {
    			headA = headB_bak;
    		}

    		if(headB != NULL)
            {
    			headB = headB->next;
    		}
            else
            {
    			headB = headA_bak;
    		}
    	}
    	return headA;
    }
};
```