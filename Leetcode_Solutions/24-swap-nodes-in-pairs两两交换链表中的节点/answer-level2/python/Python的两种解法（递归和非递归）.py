大体上对于链表的操作要么就是指针遍历要么就是递归。
非递归思路：定义多个指针遍历数组，每一步两两交换，注意两个节点交换后，之前节点的next也要改变。
递归思路：隔两个元素向下递归，回溯过程中改变next。**（递归是真的巧妙）**

```
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 非递归
        # if head is None or head.next is None: return head
        # newhead, pre, fir, sec, tmp = head.next, None, head, head.next, head.next.next
        # while sec or tmp:
        #     sec.next, fir.next = fir, tmp
        #     if pre:
        #         pre.next = sec 
        #     pre = fir
        #     fir = tmp
        #     sec = fir.next if fir else None
        #     tmp = sec.next if sec else None
        # return newhead
        
        # 递归
        if head is None or head.next is None: return head
        node = head.next
        head.next = self.swapPairs(node.next)
        node.next = head
        return node

```
