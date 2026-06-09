### 解题思路
省内存，耗时间。
记得要考虑边缘情况，尤其是有链表仅有一个元素时。

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
        if(pA->next ==NULL){//链表A只有一个元素
            while(pB->next != NULL){
                pB = pB->next;
                if(pA == pB) 
                    return pB;
                return NULL;
            }
        }
        if(pB->next ==NULL){//链表B只有一个元素
            while(pA->next != NULL){
                pA = pA->next;
                if(pA == pB)
                    return pA;
                return NULL;
            }
        }
        while(pA->next && pB->next){
            pA = pA->next;
            pB = pB->next;
        }
        if(pB->next == NULL){
            pB = headA;//pB先到末尾，则让pB回到链表A的头
        }
        if(pA->next == NULL){
            pA = headB;//pA先到末尾，让pA回到链表B的头
        }
        while(pA->next && pB->next){
            pA = pA->next;
            pB = pB->next;       
        }
        if(pB->next == NULL){
            pB = headA;//pB先到末尾，则让pB回到链表A的头
        }
        if(pA->next == NULL){
            pA = headB;//pA先到末尾，让pA回到链表B的头
        }
        while(pA != pB && pA &&pB){
            pA = pA->next;
            pB = pB->next;
        }
        if(pA == NULL){//没交点
            return NULL;
        }
        return pA;
        
    }
};
```