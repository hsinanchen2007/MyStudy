# 两次遍历
两次遍历的方式很好理解，先遍历一次链表，求出链表的总长度。   
第二次遍历的时候，根据总长度k的值-n，就算出需要再遍历多少个节点，找到要删除的节点的前一个节点x。   
然后将x节点的next指针指向下下一个节点就可以删除节点了。   
   
代码实现：
```java []
class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		if(head==null || n<=0) {
			return head;
		}
		//增加一个特殊节点，方便边界处理
		ListNode p = new ListNode(-1);
		p.next = head;
		ListNode cur = p;
		int k = 0;
		//第一次遍历，计算链表总长度
		while(cur.next!=null) {
			cur = cur.next;
			++k;
		}
		//如果链表总长度小于n，那就直接返回
		if(k<n) {
			return head;
		}
		//计算第二次遍历多少个节点
		int num = k-n;
		cur = p;
		//第二次遍历，找到要删除节点的前一个节点
		while(num>0) {
			cur = cur.next;
			--num;
		}
		//删除节点，并返回
		cur.next = cur.next.next;
		return p.next;
	}
}
```
```python []
class Solution(object):
	def removeNthFromEnd(self, head, n):
		"""
		:type head: ListNode
		:type n: int
		:rtype: ListNode
		"""
		if not head or n<=0:
			return head
		# 增加一个特殊节点，方便边界处理
		p = ListNode(-1)
		p.next,a,b,k = head,p,p,0
		# 第一次遍历，计算链表总长度
		while a.next:
			a,k = a.next,k+1
		# 如果链表总长度小于n，那就直接返回
		if k<n:
			return head
		# 计算第二次遍历多少个节点
		num = k-n
		# 第二次遍历，找到要删除节点的前一个节点
		while num>0:
			b,num = b.next,num-1
		# 删除节点，并返回
		b.next = b.next.next
		return p.next
```
   
   
   
# 一次遍历
当链表总长度是k时，如果要删除倒数第n个节点(假设n小于k)，那么首先要找到第k-n个节点，k-n这个节点就是要删除的节点的前一个节点。   
当找到k-n这个节点就好办了，直接将k-n的next指针指向下下一个节点即可。   
我们需要两个指针a和b。   
b指针先走n步，接着a和b指针同时往前走，当b指针走到链表末尾时，a指针就正好走到要删除的节点的前一个位置了，最后a节点的next指针指向下下一个节点，就可以完成删除操作了。   
![19.删除链表倒数n个节点.gif](https://pic.leetcode-cn.com/6ca1b293adce7a473b5bee6b5f0838e20aa773af811373b2974f96e744e46e9d-19.%E5%88%A0%E9%99%A4%E9%93%BE%E8%A1%A8%E5%80%92%E6%95%B0n%E4%B8%AA%E8%8A%82%E7%82%B9.gif)
   
代码实现：
```java []
class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		//增加一个特殊节点方便边界判断
		ListNode p = new ListNode(-1);
		p.next = head;
		ListNode a = p;
		ListNode b = p;
		//第一个循环，b指针先往前走n步
		while(n>0 && b!=null) {
			--n;
			b = b.next;
		}
		//假设整个链表长5，n是10，那么第一次遍历完后b就等用于空了
		//于是后面的判断就不用做了，直接返回
		if(b==null) {
			return head;
		}
		//第二次，b指针走到链表最后，a指针也跟着走
		//当遍历结束时，a指针就指向要删除的节点的前一个位置
		while(b.next!=null) {
			a = a.next;
			b = b.next;
		}
		//删除节点并返回
		a.next = a.next.next;
		return p.next;
	}
}
```
```python []
class Solution(object):
	def removeNthFromEnd(self, head, n):
		"""
		:type head: ListNode
		:type n: int
		:rtype: ListNode
		"""
		# 增加一个特殊节点方便边界判断
		p = ListNode(-1)
		p.next,a,b = head,p,p
		# 第一个循环，b指针先往前走n步
		while n>0 and b:
			b,n = b.next,n-1
		# 假设整个链表长5，n是10，那么第一次遍历完后b就等用于空了
		# 于是后面的判断就不用做了，直接返回
		if not b:
			return head
		# 第二次，b指针走到链表最后，a指针也跟着走
		# 当遍历结束时，a指针就指向要删除的节点的前一个位置
		while b.next:
			a,b = a.next,b.next
		# 删除节点并返回	
		a.next = a.next.next
		return p.next	
```
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)