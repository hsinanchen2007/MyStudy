### 解题思路
最优解中的简约神仙代码不是我这种俗人能想出来的，我还是习惯if()。

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
        ListNode* pA = headA;//为了不破坏原链表的结构
        ListNode* pB = headB;

        while(pA != pB){
            if(pA == NULL){
                pA = headB;
            }
            if(pB == NULL){
                pB = headA;
            }
            if(pA == pB) return pA;
            pA = pA->next;
            pB = pB->next;  
        }   
        return pA;     
    }
};
```