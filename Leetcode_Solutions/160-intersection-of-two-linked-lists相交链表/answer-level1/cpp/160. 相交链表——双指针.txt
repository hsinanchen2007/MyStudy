### 解题思路

长链+短链中非相交部分 = 短链+长链中非相交部分

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
        ListNode *pA,*pB;
        pA = headA;
        pB = headB;
        while(pA!=pB){
            pA = (pA==NULL)? headB:pA->next;
            pB = (pB==NULL)? headA:pB->next;
        }
        return pA;
    }
};
```