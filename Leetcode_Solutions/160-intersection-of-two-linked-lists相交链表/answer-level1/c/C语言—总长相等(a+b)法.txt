### 解题思路
本次解答完全参照高赞题解解法，很Niubility。
原理：假设a为headA**独有**的前半段，b为headB**独有**的前半段,c为**共有段**，则：
    a+c+b == b+c+a 理解这个次序，最终在c处相遇。
若headA与headB没有共有段(没有c),则：
    a+b = b+a 最终都指向NULL
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
    if(headA==NULL||headB==NULL) return NULL;
    struct ListNode *pa=headA,*pb=headB;
    while(pa!=pb){          //pa或pb不同时为val或NULL时
        //右移,到NULL时下一次滑到对方的头部
        pa=pa==NULL?headB:pa->next;
        pb=pb==NULL?headA:pb->next;
    }
    return pa;
}
```