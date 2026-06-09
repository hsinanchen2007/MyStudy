### 解题思路
计算A链表的长度和B链表的长度，然后将长的链表首先往前走|A-B|使得剩余结点和短的链表一样长，然后使用一个while判断，每一对结点是否相同，相同返回

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
        if(headA==nullptr||headB==nullptr)return nullptr;
        int lengthA=0;
        int lengthB=0;
        ListNode* curA=headA;
        ListNode* curB=headB;
        while(curA!=nullptr){
            curA=curA->next;
            ++lengthA;
        }
        while(curB!=nullptr){
            curB=curB->next;
            ++lengthB;
        }
        curA=headA;
        curB=headB;
        int minusLength=0;
        if(lengthA>=lengthB){
           minusLength=lengthA-lengthB;
           while(minusLength!=0){
               curA=curA->next;
               --minusLength;
           }
        }
        else{
            minusLength=lengthB-lengthA;
            while(minusLength!=0){
               curB=curB->next;
               --minusLength;
           } 
        }
        while(curA&&curB){
            if(curA==curB) return curA;
            curB=curB->next;
            curA=curA->next;
        }
        return nullptr;
    }
};
```