c++ 双指针 ， 把两个链表分别前后连起来变成两个等长的链表，同时不断向后移动，直到找到相同地址即相交点时停下来返回即可。
比如 4 1 8 4 5 5 0 1 8 4 5 
以及 5 0 1 8 4 5 4 1 8 4 5 
很明显可以看出后面的8 开始的8 4 5的地址都是重复的了，即为相交点。 
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr) return NULL;
        ListNode *a = headA;
        ListNode *b = headB;
        while(a!=b){
            if(!a) a = headB;
            else a = a->next;
            if(!b) b = headA;
            else b = b->next;
        }
        return a;
    }
};
```
