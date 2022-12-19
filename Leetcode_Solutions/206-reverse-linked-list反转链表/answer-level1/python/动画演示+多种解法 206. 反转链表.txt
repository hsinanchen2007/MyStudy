
### 利用外部空间
这种方式很简单，先申请一个动态扩容的数组或者容器，比如 ArrayList 这样的。
然后不断遍历链表，将链表中的元素添加到这个容器中。
再利用容器自身的 API，反转整个容器，这样就达到反转的效果了。
最后同时遍历容器和链表，将链表中的值改为容器中的值。
因为此时容器的值是：
```
5 4 3 2 1
```
链表按这个顺序重新被设置一边，就达到要求啦。   
当然你可以可以再新创建 N 个节点，然后再返回，这样也可以达到目的。   
这种方式很简单，但你在面试中这么做的话，面试官 100% 会追问是否有更优的方式，比如不用外部空间。所以我就不做代码和动画演示了，下面来看看如何用 $O(1)$ 空间复杂度来实现这道题。   
   
### 双指针迭代
我们可以申请两个指针，第一个指针叫 pre，最初是指向 null 的。   
第二个指针 cur 指向 head，然后不断遍历 cur。   
每次迭代到 cur，都将 cur 的 next 指向 pre，然后 pre 和 cur 前进一位。   
都迭代完了(cur 变成 null 了)，pre 就是最后一个节点了。   
动画演示如下：   
![迭代.gif](https://pic.leetcode-cn.com/7d8712af4fbb870537607b1dd95d66c248eb178db4319919c32d9304ee85b602-%E8%BF%AD%E4%BB%A3.gif)

代码实现：
```Java []
class Solution {
	public ListNode reverseList(ListNode head) {
		//申请节点，pre和 cur，pre指向null
		ListNode pre = null;
		ListNode cur = head;
		ListNode tmp = null;
		while(cur!=null) {
			//记录当前节点的下一个节点
			tmp = cur.next;
			//然后将当前节点指向pre
			cur.next = pre;
			//pre和cur节点都前进一位
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
}
```
```Python []
class Solution(object):
	def reverseList(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		# 申请两个节点，pre和 cur，pre指向None
		pre = None
		cur = head
		# 遍历链表，while循环里面的内容其实可以写成一行
		# 这里只做演示，就不搞那么骚气的写法了
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
   
   		
### 递归解法
这题有个很骚气的递归解法，递归解法很不好理解，这里最好配合代码和动画一起理解。
递归的两个条件：
1. 终止条件是当前节点或者下一个节点==null
2. 在函数内部，改变节点的指向，也就是 head 的下一个节点指向 head 递归函数那句
```
head.next.next = head
```
很不好理解，其实就是 head 的下一个节点指向head。   
递归函数中每次返回的 cur 其实只最后一个节点，在递归函数内部，改变的是当前节点的指向。   
动画演示如下：   
![递归.gif](https://pic.leetcode-cn.com/dacd1bf55dec5c8b38d0904f26e472e2024fc8bee4ea46e3aa676f340ba1eb9d-%E9%80%92%E5%BD%92.gif)
   
   
   
代码实现：
```Java []
class Solution {
	public ListNode reverseList(ListNode head) {
		//递归终止条件是当前为空，或者下一个节点为空
		if(head==null || head.next==null) {
			return head;
		}
		//这里的cur就是最后一个节点
		ListNode cur = reverseList(head.next);
		//这里请配合动画演示理解
		//如果链表是 1->2->3->4->5，那么此时的cur就是5
		//而head是4，head的下一个是5，下下一个是空
		//所以head.next.next 就是5->4
		head.next.next = head;
		//防止链表循环，需要将head.next设置为空
		head.next = null;
		//每层递归函数都返回cur，也就是最后一个节点
		return cur;
	}
}
```
```Python []
class Solution(object):
	def reverseList(self, head):
		"""
		:type head: ListNode
		:rtype: ListNode
		"""
		# 递归终止条件是当前为空，或者下一个节点为空
		if(head==None or head.next==None):
			return head
		# 这里的cur就是最后一个节点
		cur = self.reverseList(head.next)
		# 这里请配合动画演示理解
		# 如果链表是 1->2->3->4->5，那么此时的cur就是5
		# 而head是4，head的下一个是5，下下一个是空
		# 所以head.next.next 就是5->4
		head.next.next = head
		# 防止链表循环，需要将head.next设置为空
		head.next = None
		# 每层递归函数都返回cur，也就是最后一个节点
		return cur
```
(全文完)
    
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)
