### 解题思路
两种思路
第一种是常规思路，设置两个指针，较长链表指针先行走abs(lengthA-lengthB)步，之后两指针同步前进，直到在两链表交点处相遇
第二种需要技巧性，需要多看题才能想到，即构造一个长度为lengthA+lengthB的链表

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
        if(headA == nullptr || headB == nullptr)//判断边缘输入情况
            return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA->next != nullptr)
            pA = pA->next;//遍历链表A
        while(pB->next != nullptr)
            pB = pB->next;//遍历链表B
        if(pA != pB)////两个相交链表末节点一定相同，很多题解没有考虑这种情况
            return nullptr;
        pA = headA;
        pB = headB;
        while(pA != pB)
        {
            if(pA == nullptr)//遍历长度为lengthA+lengthB的链表
            {
                pA = headB;
                continue;
            }
            if(pB == nullptr)
            {
                pB = headA;
                continue;   
            }
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};
```
<!-- class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode* pA = headA;
        ListNode* pB = headB;
        int lengthA = 0;
        int lengthB = 0;
        while(pA->next != nullptr)
        {
            lengthA ++;
            pA = pA->next;
        }
        while(pB->next != nullptr)
        {
            lengthB ++;
            pB = pB->next;
        }
        if(pA != pB)
            return nullptr;
        pA = headA;
        pB = headB;
        if(lengthA > lengthB)
            for(int i=1;i<=lengthA-lengthB;i++)
                pA = pA->next;  
        else
            for(int i=1;i<=lengthB-lengthA;i++)
                pB = pB->next;
        while(1)
        {
            if(pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
    } -->