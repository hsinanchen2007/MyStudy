根据题意,两个链表相交的点是指: 两个指针指向的内容相同,则说明该结点记在A链表上又在B链表上,进而说明A和B是相交的

而对于相交的情况,两条链表一定是这种结构:
![ListNode.png](https://pic.leetcode-cn.com/9361ba6ca0b2203a0304156cb3d5e10337836d52f4a41464b66854ea0562418f-ListNode.png)

为什么呢?
因为如果链表A和链表B相交于D的话,那么说明D结点即在A上又在B上,而D之后的元素自然也就均在A和B上了,因为他们是通过next指针相连的.

如果有相交的结点D的话,每条链的头结点先走完自己的链表长度,然后回头走另外的一条链表,那么两结点一定为相交于D点,因为这时每个头结点走的距离是一样的,都是 AD + BD + DC,而他们每次又都是前进1,所以距离相同,速度又相同,固然一定会在相同的时间走到相同的结点上,即D点

```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA; ListNode *t2 = headB;
        while(t1 != t2){
            if (t1 == NULL)
                t1 = headB;
            else t1 = t1->next;
            if (t2 == NULL)
                t2 = headA;
            else t2 = t2->next;
        }
        return t1;
    }
};
```

