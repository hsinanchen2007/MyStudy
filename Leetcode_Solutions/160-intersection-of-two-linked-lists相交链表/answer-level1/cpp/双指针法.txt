参考官方的解法三：
1.定义两个指针p=headA，q=headB
2.两个指针同步遍历，遇到NULL则指向另一个链表头节点
3.两个指针最终必会相遇：
                        1.如果是相交链表则相遇在交点
                        2.如果不是，则两个指针值为NULL
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB ==NULL)
            return NULL;
        ListNode *p=headA,*q = headB;
        while(p!=q){
            p = p==NULL ? headB:p->next;
            q = q==NULL ? headA:q->next;
        }
        return p;
    }
};
```
