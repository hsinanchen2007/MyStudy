以K个为一个整体来看，我们需要定位三个位置，一个指向链表首节点的指针h，一个此段链表初始的第一个节点g_0，以及从节点f往后遍历的节点g_i；
翻转链表=将每个g_0.next的节点g_i放到h.next，一段长度为k的链表需要执行k-1次。

第一次的情况：
![image.png](https://pic.leetcode-cn.com/d7e9dd37137c1a648a39caed5655425b181ab3310b3672ee721f201e6ed1b744-image.png)
第i次的情况：
![image.png](https://pic.leetcode-cn.com/eea3aeb43eb46d058f8d0ea1f35dabfc9da2ffe16afed7d4edf23c74768c4101-image.png)
python3代码如下：
```
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 所谓的颠翻转其实可以理解为，规定指向下一轮k个节点的指针h，将后面顺序遍历到的k个节点依次放到h.next，这样就可以达到翻转的效果

        # 返回第k个节点，作为下一次翻转的头节点h
        def pair_rev(h) -> ListNode:
            # 记下此段的第一个节点记为f，需要前置的节点是f.next(即节点g)
            f = h.next
            for _ in range(k-1):
                g = f.next
                f.next = g.next
                g.next = h.next
                h.next = g
            return f

        # 得到链表的长度，进而得到需要翻转的次数
        flag,n = head,0
        while flag:
            flag = flag.next
            n += 1
        times = n//k
        
        # 新建一个节点指向链表
        a = ListNode(-1)
        a.next = head
        # 执行times次
        for _ in range(times):
            h0 = pair_rev(a)
        return a.next
                    
```


