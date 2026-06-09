### 解题思路
1 求出每个链表长度以及长度差值
2 长的先移动差值步，两个链表等长
3 两个链表同时遍历查找

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
        int len1=0,len2=0;
        ListNode *headA0=headA;
        ListNode *headB0=headB;
        while(headA0)
        {
            headA0=headA0->next;
            len1++;
        }
        while(headB0)
        {
            headB0=headB0->next;
            len2++;
        }
        if(len1>len2)
        {
            int len=len1-len2;
            while(len)
            {
                headA=headA->next; 
                len--; 
            }  
        }
        else
        {
            int len=len2-len1;
            while(len)
            {
                headB=headB->next; 
                len--; 
            } 
        }

        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};
```