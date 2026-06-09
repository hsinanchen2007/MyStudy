### 解题思路
参照
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/

原理：
https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/161874
你的总路程：A链表节点数+B链表节点数
我的总路程：B链表节点数+A链表节点数
加法有交换律率，所以我们总路程相同。在同速度的情况下，如果路径相交，必然会在路程交点相遇。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* Ap=headA;
    struct ListNode* Bp=headB;
    while(Ap!=Bp)
    {
        Ap= Ap==0?headB:Ap->next;
        Bp= Bp==0?headA:Bp->next;
    }
    return Ap;
}
```