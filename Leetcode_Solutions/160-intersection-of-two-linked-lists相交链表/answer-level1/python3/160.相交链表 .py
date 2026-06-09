- **思路**：将两个链表想象成前段不同但后段相同的两条路，现在有两个运动速度一样的运动员从两条路的起点开始跑，当跑到路的终点时又跳到另一条路的起点开始跑。则运动员第二次到达两条路的交叉路口时，他们所跑过的距离一样：两条路相交前的距离之和加上后面的重叠部分！因为速度一样，所以必然会在交叉路口相遇，即相遇点就是该题所求的相交节点！
- **代码化**：设置两个分别指向链表头部的指针，同步往后移动，到达末尾便跳向另一个链表的头部，当两个指针到达同一节点时，便是相交的起始节点。
```
# Definition for singly-linked list.pyt
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        pre_A = headA
        pre_B = headB
        if pre_A == None or pre_B == None:
            return None
        while pre_A != pre_B:
            pre_A = headB if pre_A == None else pre_A.next
            pre_B = headA if pre_B == None else pre_B.next
        return pre_A
```
