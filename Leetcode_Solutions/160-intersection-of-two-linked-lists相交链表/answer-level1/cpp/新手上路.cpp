使用set特性，判断其大小，要是添加之后大小与oldsize一直则是相交链表，返回当前节点
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
            set<ListNode *> ret;
            while (headA)
            {
                ret.insert(headA);
                headA=headA->next;
            }
            while (headB)
            {
                int oldsize = ret.size();
                ret.insert(headB);
                if (oldsize == ret.size ()) return headB;
                headB = headB->next;
            }
            return headB;
        }
    };
```
