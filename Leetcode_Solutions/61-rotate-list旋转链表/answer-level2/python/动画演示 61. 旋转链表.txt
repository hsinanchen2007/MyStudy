# 题解
以示例1为例 ```1->2->3->4->5```，k=2，那么移动完就是：
```4->5->1->2->3```
移动一次的时候是 ```5->1->2->3->4```，移动两次就是```4->5->1->2->3```。
看出什么端倪了吗？
关键点就是k，如果移动一次就相当于将倒数第一个元素1移到链表开头，如果移动两次就相当于将倒数第二和倒数第一个元素2和1移动到链表开头。   
所以这题的关键是要找到倒数第k个节点。   
在这之前我们还需要处理一些细节：   
当k等于链表总长时，就相当于移动0次，也就是啥也不用做直接返回就行了。如果k>链表总长，比如k=7时，结果仍然是```5->4->3->2->1```。   
所以我们要先对k取模，取模后的k范围应该是：    
```1<=k<=链表总长-1```   
找到倒数第k个节点4，然后将链表的尾部指向开头   
![1.jpg](https://pic.leetcode-cn.com/d571a8460cde1c65a31d3c49610f6397c324ed499ded47f4297cb3e1cc91fe5d-1.jpg)
   
再将节点4前面一个3的next指向null，一定要断开，否则链表就成环状啦   
![2.jpg](https://pic.leetcode-cn.com/076ce46528dc3c905f87ed38617000d404e94b860be52f268a2cde1fa5fb8719-2.jpg)
   
最后返回新的头结点4就可以了   
![3.jpg](https://pic.leetcode-cn.com/7f5f8048731a3a7cac0170c94f906221e0c62c7e25590e934fc5271eeadf618f-3.jpg)
   
动态演示如下：    
![动态图.gif](https://pic.leetcode-cn.com/417024b718e4920e6fcc4a07df76e2109f9f55e023f0e0af25be7e8ab378a6bb-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)
   
   
代码实现:   
```java []
class Solution {
	public ListNode rotateRight(ListNode head, int k) {
		if(head==null || k<=0) {
			return head;
		}
		//创建一个特殊节点，快指针，慢指针，统计节点个数的cur
		ListNode p = new ListNode(-1);
		p.next = head;
		ListNode cur = p;
		ListNode low = p;
		ListNode fast = p;
		int n = 0;
		//统计链表个数
		while(cur.next!=null) {
			cur = cur.next;
			++n;
		}
		//边界条件不用忘记处理了
		//其实有这段最上面的head==null可以省略
		if(n==0 || k%n==0) {
			return head;
		}
		//还有一个边界条件不要忘了，k可能大于n，所以要取模
		n = k%n;
		//快指针先移动n步
		while(fast.next!=null && n>0) {
			fast = fast.next;
			--n;
		}
		//快指针，慢指针一起移动，找到需要切割的点
		while(fast.next!=null) {
			low = low.next;
			fast = fast.next;
		}
		//改变链表的指向关系，注意这里的步骤不要乱了
		//先让fast节点指向head(也就是p.next)
		//再是head(也就是p.next)指向low的下一个节点
		//这两步如果弄反了就会出现节点丢失了
		//最后不要忘记将low.next置空
		fast.next = p.next;
		p.next = low.next;
		low.next = null;
		return p.next;
	}
}
```
```python []
class Solution(object):
	def rotateRight(self, head, k):
		"""
		:type head: ListNode
		:type k: int
		:rtype: ListNode
		"""
		# 下面有 if n==0 ...判断了，所以开头的判断可以省略
		#if not head or k<=0:
		#    return head
		# 创建一个特殊节点，快指针，慢指针，统计节点个数的cur
		p = ListNode(-1)
		cur,n,low,fast,p.next = head,0,p,p,head
		# 统计链表个数
		while cur:
			cur,n = cur.next,n+1
		# 边界条件不用忘记处理了	
		if n==0 or k%n==0:
			return head
		# 还有一个边界条件不要忘了，k可能大于n，所以要取模
		n = k%n
		# 快指针先移动n步
		while fast.next and n>0:
			fast,n = fast.next,n-1
		# 快指针，慢指针一起移动，找到需要切割的点
		while fast.next:
			low,fast = low.next,fast.next
		# 改变链表的指向关系，注意这里的步骤不要乱了
		# 先让fast节点指向head(也就是p.next)
		# 再是head(也就是p.next)指向low的下一个节点
		# 这两步如果弄反了就会出现节点丢失了
		# 最后不要忘记将low.next置空
		fast.next,p.next,low.next = head,low.next,None
		return p.next
```
(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)