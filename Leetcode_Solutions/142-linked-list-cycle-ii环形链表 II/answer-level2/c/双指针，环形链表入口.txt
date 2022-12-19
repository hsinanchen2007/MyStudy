![image.png](https://pic.leetcode-cn.com/4be79c49cdeb58d5ef43184c381cda422813b708226af7dc4818d4ed98466289-image.png)

求入环节口就几个公式，用快慢指针
才搞明白，官方题解较清楚

一个指针q步数是另一个p的2倍，那么q走的距离也是p的二倍

都从头走，相遇后快的再回到头，再同时与慢的以一步速度往下走，会相遇在入口

![image.png](https://pic.leetcode-cn.com/7a70e8f3a35695dd69e50a3b7ff8c4f442001b622bdc5f3dbbb0c5e13e680685-image.png)

看官方的动画好明白


```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL) return NULL;
    struct ListNode *p = head, *q = head;
    do {
        if(p->next == NULL) return NULL;
        p = p->next;
        if(q->next && q->next->next) q = q->next->next;
        else return NULL;
    } while(p != q);
    q = head;
    while(p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}
```
