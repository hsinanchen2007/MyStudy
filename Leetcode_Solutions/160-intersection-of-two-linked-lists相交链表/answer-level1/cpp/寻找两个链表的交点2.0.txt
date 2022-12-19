### 解题思路
题目要求找出两个链表的交点。
一开始想到哈希表维护，然后突然想到双重循环，也就是暴力枚举，当时以为两者时间复杂度差不多。而后者思路更加简单。就写了后者。
然后执行结果不是很好。看了官方答案，三种方法，想到了前面两种。于是用第三种方法。第三种方法大致意思就是维护两个指针，假设有一个相交结点P,
因为headA,headB，到达p的距离是不一样的，为了让他们的距离一样，可以在其中任何一个指针走到尾结点或者NULL时，指向对方的首地址。这样
粗略理解就是，因为某个链表首地址到相交点短一些，那么第一次先到，那么再让他从对方的首地址走，因为这个距离长些，走的多些，这一消一涨就弥补了
差距，也就是说，在两个指针都走了对方的路后，那么这个时刻以后，两个指针到相交结点的步数相同。最坏情况是O(M+N)，空间复杂度上只需要维护两个指针即可

### 代码

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB) return NULL;
        ListNode *pa,*pb;
        pa=headA;
        pb=headB;
        while(pa!=pb){
            if(!pa) pa=headB;
            else pa=pa->next;
            if(!pb) pb=headA;
            else pb=pb->next;
        }
        if(pa) return pa;
        else return NULL;
    }
};
```