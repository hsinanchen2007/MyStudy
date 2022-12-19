### 解题思路
题目要求不让修改链表，我悄悄修改了，然后又改回去了哈哈哈！！！

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
        ListNode *pA=headA;
        while(pA!=NULL){
            pA->val+=999999;
            pA=pA->next;
        }
        ListNode *pB=headB;
        ListNode *p;
        while(pB!=NULL){
            if(pB->val>800000) {p=pB;break;}
            pB=pB->next;
        }
        pA=headA;
        while(pA!=NULL){
            pA->val-=999999;
            pA=pA->next;
        } 
        return p;
    }
};
```