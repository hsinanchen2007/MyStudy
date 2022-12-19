# 我只是来打个卡
```
class Solution(object):
	def reverseList(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		pre = None
		cur = head
		while cur:
			tmp = cur.next
			cur.next = pre
			pre = cur
			cur = tmp
		return pre
```
