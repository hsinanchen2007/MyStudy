一个指针从a 链走，另一个从b 链走，如果指针走到null 时，跳转到另一条链头开始走，
如果链表相交，指针会最终相遇，否则，不相交。
```
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
        auto p=headA,q=headB;
        while(p!=q)
        {
            if(p) p=p->next;
            else p=headB;
            if(q) q=q->next;
            else q=headA;
        }
        return p;
    }
};
```
