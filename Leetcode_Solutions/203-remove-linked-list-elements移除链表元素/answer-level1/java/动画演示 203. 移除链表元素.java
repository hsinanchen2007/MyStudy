# 题解
这道题是要求我们删除链表中指定的元素，也就是某些特定的节点。
如果已经遍历到一个节点时，就无法删除这个节点了，因为是单链表。
所以想要删除某个节点，就必须找到这个节点的前一个节点，把前一个节点的指针改变，即指向下下一个就可以达到删除的目的了。
动画演示如下： 
![203.移除链表元素.gif](https://pic.leetcode-cn.com/0d26a92c3280a29e5672b37f6dae4739e99927313608696e2ce420ce0e3ab415-203.%E7%A7%BB%E9%99%A4%E9%93%BE%E8%A1%A8%E5%85%83%E7%B4%A0.gif)



代码实现：
```java []
class Solution {
	public ListNode removeElements(ListNode head, int val) {
		ListNode p = new ListNode(-1);
		p.next = head;
		//因为要删除的可能是链表的第一个元素，所以用一个h节点来做处理
		//最后只要返回h的下一个节点即可
		ListNode h = p;
		//注意遍历的条件是p.next不为空
		while(p.next!=null) {
			//如果p的下一个节点的值==val
			//P就指向下下一个，这就删掉了指定的节点
			if(p.next.val==val) {
				p.next = p.next.next;
				//注意这里的continue
				//因为循环最后还有一个P=p.next，所以要跳过
				continue;
			}
			//不用continue用else的方式也是可以的
			p = p.next;
		}
		return h.next;
	}
}
```
```python []
class Solution(object):
	def removeElements(self, head, val):
		"""
		:type head: ListNode
		:type val: int
		:rtype: ListNode
		"""
		p = ListNode(-1)
		# 因为要删除的可能是链表的第一个元素，所以用一个h节点来做处理
		# 最后只要返回h的下一个节点即可
		p.next,h = head,p
		# 注意遍历的条件是p.next不为空
		while p.next:
			# 如果p的下一个节点的值==val
			# P就指向下下一个，这就删掉了指定的节点
			if p.next.val==val:
				p.next = p.next.next
				# 注意这里的continue
				# 因为循环最后还有一个P=p.next，所以要跳过
				continue
			# 不用continue用else的方式也是可以的
			p = p.next
		return h.next
```

(全文完)  
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)