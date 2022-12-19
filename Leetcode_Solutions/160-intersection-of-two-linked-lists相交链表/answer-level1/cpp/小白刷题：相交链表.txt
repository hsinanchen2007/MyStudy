先遍历求出两链表长度，之后两指针指向两链表头结点，利用长度差将两指针对齐，最后挪动指针，直至两指针相等，即为相交结点

代码：
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* p = headA;
        ListNode* q = headB;
        while (p) {
            p = p->next;
            lenA++;
        }
        while (q) {
            q = q->next;
            lenB++;
        }
        p = headA;
        q = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++)
                p = p->next;
        }
        else {
            for (int i = 0; i < lenB - lenA; i++)
                q = q->next;
        }
        while (p != q) {
            p = p->next;
            q = q->next;
        }
        return p;
    }
};
```
