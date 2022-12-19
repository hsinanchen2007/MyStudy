### 解题思路
主要的思想还是先整理链表长度一致，然后按顺序比较

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
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* hA = headA;
        ListNode* hB = headB;
        int na=0;
        int nb=0;
        while(1) 
        {
            if(headA != NULL) 
            {
                headA = headA -> next;
                na++;
            }
            if(headB != NULL) 
            {
                headB = headB -> next;
                nb++;
            }
           if(headB == NULL && headA == NULL ) break;
        }
        int d=na-nb;
        if (d>0)
        {
            while(d>0)
            { hA = hA-> next;
            d--;}
        }
        else
        {
            d=nb-na;
            while(d>0)
            { hB = hB-> next;
            d--;}
        }
        while(hA != NULL && hB != NULL)
        {
            if(hA==hB)
            {
                return hA;
            }
            hA = hA-> next;
            hB = hB-> next;
        }
        return NULL;
        }
};
```