-思路 :
想一想我们数学学的追及问题,相信很多人都有印象,想像一下一个操场,速度快的人肯定先到达终点,要是环形的跑道就会存在一个相遇问题.如果最后相遇了不就形成环了吗 .

这里设定两个指针 p和  q 都指向头结点 我们让q跑的快一点,没有相遇就没有环,反之,让p和q先走一步,我们用到  do ....while循环.

```
bool hasCycle(struct ListNode *head) {
    struct ListNode *p = head , *q = head;
    if (p == NULL) return false;
    do {
        p = p->next ;
        q = q->next;
        if (q == NULL || q->next == NULL) return false;
        q = q->next;
    } while (p != q);
    return true;
}
```
