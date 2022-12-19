循环法: 思路不算难，但细节需要注意，尤其是首节点和尾节点时候是否合法，还有如何写出简洁的代码。能不定义变量就尽量不定义。

~~~python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        left = None
        now = head
        while now is not None:
            right = now.next
            now.next = left
            left=now
            now = right
        return left         
~~~

递归法: 由于返回的是原链表的最后一个节点，所以使用自上而下的递归方法。也即先反转前面的，递归到最后时，返回最后一个节点。不过这个递归与前面的循环没有本质区别，还有一种更骚的递归。这种递归减少了right和left变量，直接用head.next与head.next.next代替。

~~~python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        def digui(left,now):
            if now is None:
                return left
            right = now.next
            now.next = left
            return digui(now,right)
        return digui(None,head)
            
~~~

~~~python
class Solution(object):
	def reverseList(self, head):
		if(head==None or head.next==None):
			return head
		cur = self.reverseList(head.next)
		head.next.next = head
		head.next = None
		return cur
~~~

