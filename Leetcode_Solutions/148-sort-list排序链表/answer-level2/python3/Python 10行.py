```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not (head and head.next): return head
        pre, slow, fast = None, head, head
        while fast and fast.next: pre, slow, fast = slow, slow.next, fast.next.next
        pre.next = None
        return self.mergeTwoLists(*map(self.sortList, (head, slow)))
    
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            if l1.val > l2.val: l1, l2 = l2, l1
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1 or l2
```
- 使用快慢指针寻找链表中点，并分解链表
- 递归融合俩个有序链表，详解见 21 题
- 此处忽略了递归开栈导致的非 常数级空间复杂度（想太多了吧:laughing:），如果一定要抬杠，推荐使用quicksort
	```python
	class Solution(object):
	    def sortList(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		def partition(start, end):
		    node = start.next.next
		    pivotPrev = start.next
		    pivotPrev.next = end
		    pivotPost = pivotPrev
		    while node != end:
			temp = node.next
			if node.val > pivotPrev.val:
			    node.next = pivotPost.next
			    pivotPost.next = node
			elif node.val < pivotPrev.val:
			    node.next = start.next
			    start.next = node
			else:
			    node.next = pivotPost.next
			    pivotPost.next = node
			    pivotPost = pivotPost.next
			node = temp
		    return [pivotPrev, pivotPost]

		def quicksort(start, end):
		    if start.next != end:
			prev, post = partition(start, end)
			quicksort(start, prev)
			quicksort(post, end)

		newHead = ListNode(0)
		newHead.next = head
		quicksort(newHead, None)
		return newHead.next
	```

