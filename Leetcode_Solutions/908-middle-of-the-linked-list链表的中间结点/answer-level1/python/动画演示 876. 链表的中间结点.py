
# 两次遍历方式
这道题很简单，我们只需要遍历一遍链表，就可以求得链表的节点个数。   
我们再遍历一次链表，这次只需要遍历总节点个数的一半就能取得中间节点了。   
如果链表总节点个数是偶数，假设是10，那么第二次遍历结束，当前节点就是5这个节点，然后我们返回5的下一个节点6即可。   
如果链表总节点个数是奇数，比如是9，那么第二次遍历结束后，当前节点仍然是5这个节点，这次直接返回就可以了。   
因为这个方案实在太简单了，所以我就不贴代码实现了。面试的时候如果这么写面试官肯定会追问，如何只遍历一次就可以求得中间节点。   
下面我们来看看只遍历一次的方案。   
   
   
   
# 一次遍历方式
我们需要两个额外的指针，快指针和慢指针，慢指针每次前进一位，快指针每次前进两位，当快指针遍历结束时，慢指针就刚刚落在链表中间节点的位置。   
动态演示如下：
![动画.gif](https://pic.leetcode-cn.com/f9fedacfc95c0570b9e0e317d481a92e450e6ca0ad3ceb072829a67e98a1b487-%E5%8A%A8%E7%94%BB.gif)
这里有一个细节需要注意，当链表遍历结束时，如果链表总长是偶数，那么快指针不为空，所以根据这个条件，取慢指针的下一个即可   
![1571805069(1).jpg](https://pic.leetcode-cn.com/6b782beb817fe7199187e7ed751076fd0c67d07c1d8c63d1b5ea5ee0eb57f804-1571805069\(1\).jpg)
如果链表总长是奇数快指针就是空
![1571805092(1).jpg](https://pic.leetcode-cn.com/f1b2db94f49037e9af47464415f5255c6bc1d1925e42f0ce74bafd8d70f0bc9d-1571805092\(1\).jpg)
   
代码实现如下：   
```java []
class Solution {
	public ListNode middleNode(ListNode head) {
		//边界条件不用忘记处理了
		if(head==null || head.next==null) {
			return head;
		}
		//定义慢指针，快指针
		ListNode low = head;
		ListNode fast = head.next;
		while(fast!=null && fast.next!=null) {
			//慢指针每次走一步，快指针每次走两步
			low = low.next;
			fast = fast.next.next;
		}
		//根据快指针是否为空判断边界条件
		if(fast!=null) {
			return low.next;
		}
		return low;
	}
}
```
```python []
class Solution(object):
	def middleNode(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		# 边界条件不用忘记处理了
		if not (head and head.next):
			return head
		# 定义慢指针，快指针
		low,fast = head,head.next
		while fast and fast.next:
			# 慢指针每次走一步，快指针每次走两步
			low,fast = low.next,fast.next.next
		# 根据快指针是否为空判断边界条件
		if fast:
			return low.next
		return low
```
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)