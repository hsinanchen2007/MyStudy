
因为是单链表，这样两个链表相交后是不能再分叉的，也就是会成一个横着的Y字型，那么这两个链表的后半截肯定是一样的如果它们相交的话，我们就可以倒着思考，那我从尾部开始判断，找到它们不相等的点，那么最后一个相等的点就是它们的相交点了。

但是这很不好考虑，那么我们正着想，遍历它们发现第一个相交点，但是两个链表不一样长，怎么去遍历找到第一个相交点呢？

诶，我把它们搞到一样长再一起走，那不就能找得到了吗。怎么一样长呢，我能不能让长一点的链表先走几步呢，走到和短链表一个位置，然后再让它们手牵手一起走。。

那么我得先算出两个链表的长度，找到长链表和断链表分别是哪个，然后它们相差多长，让长链表先走相差的那几步去和短链表一个起始点，如果它们在遍历结束之前遇到了同一个点，那么就返回这个点，如果它们都走完了还没有相遇，那说明没有相交，返回None。

思路就是这个，就可以写代码了：

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        if not headA or not headB:
            return None
        
        # 公共函数的抽取
        lenA = self.get_length(headA)
        lenB = self.get_length(headB)
        
        # 找到长链表、短链表以及相差多少步
        if lenA >= lenB:
            hLong = headA
            hShort = headB
            dif = lenA - lenB
        else:
            hLong = headB
            hShort = headA
            dif = lenB - lenA
        
        # 长链表先走几步
        for i in range(dif):
            hLong = hLong.next
        
        # 然后让长链表短链表一起手牵手往下走直到相遇（手牵手了都怎么叫直到相遇哈哈哈）
        while hLong and hShort:
            if hLong == hShort:
                return hLong
            hLong = hLong.next
            hShort = hShort.next
        
        # 如果遇不到那就是没缘分啦...
        return None
        
        
    def get_length(self, head):
        length = 0
        
        while head:
            length += 1
            head = head.next
        
        return length
```

（附：我也希望有个短链表能等等我追上这几步哈哈哈哈哈）

![image.png](https://pic.leetcode-cn.com/18664e104f00a9e0b5fbad2dc7b50b019d60eac39c8542f1ba759e374a37a0d1-image.png)
