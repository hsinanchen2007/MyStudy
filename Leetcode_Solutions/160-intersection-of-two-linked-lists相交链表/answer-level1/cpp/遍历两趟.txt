先遍历A再遍历B，和先遍历B再遍历A是一样的。即length(A)+length(B)==length(B)+length(A)。
所以可以让较长的链表先遍历k个节点，k为两个链表节点差值。然后继续遍历，直到找到相交节点。
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=0, lb=0;
        for(ListNode *p=headA; p; ++la, p=p->next);
        for(ListNode *p=headB; p; ++lb, p=p->next);
        if(la<lb) swap(headA, headB);
        for(la=abs(la-lb); la--; headA=headA->next);
        for(; headA!=headB; headA=headA->next, headB=headB->next);
        return headA;
    }
};
```
更加巧妙的方法，遍历完A链表，继续从头开始遍历B链表；直到找到相交点。
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(ListNode *a=headA, *b=headB; headA!=headB;){
            headA=headA?headA->next:b;
            headB=headB?headB->next:a;
        }
        return headA==headB?headA:NULL;
    }
};
```
然而实际上，方法一更快，因为方法二每次都要做地址非零判断。
