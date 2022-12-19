### 解题思路
采用递归的方法来处理每一个组的翻转，外面用一个循环便利到每一个组处理完成

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *nhead = NULL;
        if ( NULL == head || k <= 1) return head;

        ListNode *ntail = NULL;
        ListNode *p = head;
        ListNode *q, *qt;
        while ( (NULL != p) )
        {
            if( checkAndSwrap(p, k, &q, &qt) )
            {
                if ( NULL == nhead ) 
                {
                    nhead = q;
                    ntail = qt;
                }
                else {
                    ntail->next = q;
                    ntail = qt;
                }
                p = qt->next;
            }
            else{
                break;
            }
            
        }
        return nhead;
    }

    bool checkAndSwrap(ListNode* p, int k, ListNode **q, ListNode **qt)
    {
        if ( NULL == p ) { 
            return false; 
        }
        if ( k <= 1 )
        {
            *q = p;
            *qt = p;
            return true;
        }
        
        //printf("----p:%d \n", p->val);
        ListNode *nqt;
        if ( checkAndSwrap(p->next, k-1, q, &nqt) )
        {
            p->next = nqt->next;
            nqt->next = p;
            *qt = p; 
            return true;
        }
        return false;
    }
};
```