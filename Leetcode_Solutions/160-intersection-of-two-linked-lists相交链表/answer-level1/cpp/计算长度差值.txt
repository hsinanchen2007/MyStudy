### 解题思路
链表 A=a->b->c->d
    B=f->c->d
可以先计算2个链表长度，计算差值，然后将长链表head指向差值那个地方。(比如A的head指向b)，然后2个链表同时向后指，直到指导相同节点。

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
    int getLength(ListNode* node){
        ListNode* p=node;
        int count=0;
        while(node!=NULL){
            count++;
            node=node->next;
        }
        node=p;
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA=getLength(headA);
        int lengthB=getLength(headB);
        int gap=0;
        if(lengthA<=lengthB){
            gap=lengthB-lengthA;
            while(gap!=0){
                headB=headB->next;
                gap--;
            }
        }else{
            gap=lengthA-lengthB;
            while(gap!=0){
                headA=headA->next;
                gap--;
            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
        
    }
};
```