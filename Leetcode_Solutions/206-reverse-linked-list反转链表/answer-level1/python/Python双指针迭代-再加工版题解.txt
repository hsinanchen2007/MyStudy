### Python实现双指针迭代

1. 申请两个指针
第一个指针 `pre`，最初指向 `null`。
第二个指针 `cur`，最初指向 `head`。

2. 遍历 `cur`
迭代到 `cur`，将 `cur` 的 `next` 指向 `pre`(即反转指针)
接着进行 `pre` 和 `cur` 向下移动一个节点的操作

3. 迭代结束时
`cur` 变成 `Null`
`pre` 变成最后一个节点

4. 返回满足题意的 `pre`

### 代码 - 易理解版

```python
"""
	type head: ListNode
	rtype: ListNode
"""
class Solution(object):
	def reverseList(self, head):
		# 申请pre和cur两个节点，pre指向None，cur指向head
		pre = None
		cur = head
		while cur:
			# 记录当前节点的下一个节点
			tmp = cur.next
			# 然后将当前节点指向pre
			cur.next = pre
			# pre和cur节点都前进一位
			pre = cur
			cur = tmp
		return pre	
```

### 代码 - 简化版

```python
class Solution(object):
	def reverseList(self, head):
		pre,cur = None,head
		while cur:
			cur.next,pre,cur = pre,cur,cur.next
		return pre
```

内容根据 王尼玛 的题解，自己理解加工