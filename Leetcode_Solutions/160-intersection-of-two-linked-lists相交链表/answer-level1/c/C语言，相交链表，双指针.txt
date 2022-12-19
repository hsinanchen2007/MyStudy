方法1：两个单链表相交，交汇节点及之后的部分必然是相同的。先分别计算两个链表的长度`la`、`lb`，让快指针在较长的链表中先走`gap`距离对齐，然后逐一比对节点。

```C
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    int la, lb, lgap;
    for (la = 0; p; p = p->next, la++);  //链表A长度
    for (lb = 0; q; q = q->next, lb++);  //链表B长度
    lgap = la - lb;  //计算长度差
    if (la > lb){
        while (lgap--)  headA = headA->next;  //如果A更长，让A先走gap距离
    } else {
        while (lgap++)  headB = headB->next;  //反之让B先走gap距离
    }
    while (headA){  //逐一对比节点
        if (headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }
    return NULL;
}
```

方法2：指针`p`遍历`A`到达链尾时，重定向至`headB`，同样，指针`q`遍历`B`到达链尾时，重定向至`headA`。若它们在某个节点相遇，必为交点。  
初看很难理解，但是细想就会发现很简单很巧妙。`A`和`B`两个链表长度可能不同，但是`A+B`和`B+A`的长度是相同的，所以遍历`A+B`和遍历`B+A`一定是同时结束。如果相交的话，`A`和`B`有一段尾巴是相同的，所以两个指针一定会同时到达交点。
```C
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p || q){
        if (p && p == q) return p;  //非空且相等，即为交点
        p = p ? p->next : headB;  //若p走到A链尾，则重定向至headB
        q = q ? q->next : headA;
    }  //若p,q同时走到NULL，说明没有相同的尾巴，跳出循环
    return NULL;
}  //这个解法我是想不到的，看了题解写的
```