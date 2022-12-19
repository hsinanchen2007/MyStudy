### 解题思路
用一次循环找出两个链表的长度，然后长的链表减去这个长度（一次循环是减少复杂度）
然后两个链表同时开始，寻找第一个相同的结点
记得开始要检查一下是否为空的形参

### 代码
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        else
        {
            int A_long= 1 , B_long = 1;
            ListNode *A = headA , *B = headB;
            for( ; A ->next != NULL || B->next != NULL ;)
            {
                if(A ->next != NULL)
                {
                    A = A->next;
                    ++A_long;
                }
                if(B ->next != NULL)
                {
                    B = B->next;
                    ++B_long;
                }
            }
            A = headA;
            B = headB;
            if(A_long >= B_long)
            {
                for(int i = 0 ; i < A_long - B_long ; ++i )
                A = A->next;
            }
            else
            {
                for(int i = 0 ; i < B_long - A_long ; ++i )
                B = B->next;
            }
            while(A->next != NULL && A != B)
            {
                A = A->next;
                B = B->next;
            }
            if( A == B)
                return A;
            else
                return NULL;        
        }
    }
};
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
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        else
        {
            int A_long= 1 , B_long = 1;
            ListNode *A = headA , *B = headB;
            for( ; A ->next != NULL || B->next != NULL ;)
            {
                if(A ->next != NULL)
                {
                    A = A->next;
                    ++A_long;
                }
                if(B ->next != NULL)
                {
                    B = B->next;
                    ++B_long;
                }
            }
            A = headA;
            B = headB;
            if(A_long >= B_long)
            {
                for(int i = 0 ; i < A_long - B_long ; ++i )
                A = A->next;
            }
            else
            {
                for(int i = 0 ; i < B_long - A_long ; ++i )
                B = B->next;
            }
            while(A->next != NULL && A != B)
            {
                A = A->next;
                B = B->next;
            }
            if( A == B)
                return A;
            else
                return NULL;        
        }
    }
};
```
