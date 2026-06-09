### 解题思路
此处撰写解题思路

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
    //利用在相遇点走的路径相等解题
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)return NULL;       
        auto p = headA;
        auto q = headB;
        while(p != q){
            if(p)p = p->next;
            else p = headB;
            if(q)q = q->next;
            else q = headA;
        }
        return p;
    }
};
```