# 解题思路
运用双指针的方法，既然要找倒数第k个节点，我们就定义2个指针，一个左指针，一个右指针，都指向头节点，先让右指针向前遍历k-1次，此时右指针和左指针的长度就为k,我们可将其想象为一把长度为K的尺子。然后对尺子进行遍历，就是每次右指针和左指针向前走一步，知道遍历完整个链表。此时右指针指向的是链表尾部，左指针就是链表的倒数的第K个节点。
# 边界条件
如果k大于链表的长度，就是尺子超出链表的大小，直接返回False
# 代码

```
class Solution(object):
    def getKthFromEnd(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        # 如果k大于链表的长度，返回None
        # 如果k小于链表的长度，定义两个变量构成一把长度为k尺子，然后同时遍历尺子的左右，最后返回尺子左边的链表
        right = head
        left = head
        for i in range(k-1):
        # right向右走k-1步，构成长度为K的尺子
            right = right.next
            if right == None:
                return None
        while right.next!=None:
            right = right.next
            left = left.next
        return left

```
