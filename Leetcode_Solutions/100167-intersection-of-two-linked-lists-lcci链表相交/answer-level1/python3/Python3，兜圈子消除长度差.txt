# 一、思路：

通过双指针法找出较长链表与较短链表的长度差，再让较长列表从头前进长度差个节点即可。

对于任意两个链表l1和l2，假设l1比l2长，那么两个链表同时向前，当l2到达结尾时，l1剩余的长度就是l1比l2长的部分。

此时再从l1的head开始，把l1比l2长的部分消除掉，然后开始进行比较。


# 二、代码：



```
class Solution:
    
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        l1 = headA
        l2 = headB

        while l1 and l2:                  # l1和l2同时前进
            l1 = l1.next
            l2 = l2.next
        
        while l1:                         # 如果l1比l2长
            headA = headA.next            # 从headA中去掉长的部分
            l1 = l1.next
        
        while l2:                         # 如果l长
            headB = headB.next            # 从headB中去掉长的部分
            l2 = l2.next
        
        while headA != headB:             # 进行比较
            headA = headA.next
            headB = headB.next
        
        return headA
```


![微信截图_20200226200936.png](https://pic.leetcode-cn.com/4acc130be708c4705329e40f513cdb52b0813fb0707d480ffd37bc186d8de51d-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200226200936.png)
