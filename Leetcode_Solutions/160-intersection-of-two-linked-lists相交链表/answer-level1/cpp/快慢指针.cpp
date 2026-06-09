### 解题思路
执行用时 :
56 ms
, 在所有 C++ 提交中击败了
70.72%
的用户
内存消耗 :
16 MB
, 在所有 C++ 提交中击败了
100.00%
的用户

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
        int len_A = 0, len_B = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        while(q != NULL){
            len_B++;
            q = q->next;
        }
        while(p != NULL){
            len_A++;
            p = p->next;
        }
        p = headA;
        q = headB;
        while(len_A > len_B){
            p = p->next;
            len_A--;
        }
        while(len_B > len_A){
            q = q->next;
            len_B--;
        }
        while(len_B == len_A){
            if(q == p){
                return q;
                // break;
            }
            q = q->next;
            p = p->next;
        }
        return NULL;
    }
};
```