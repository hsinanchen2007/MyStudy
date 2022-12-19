## 利用堆做排序
合并两个链表我们可以用if-else做判断，但是```k```个链接，用if-else，这就没法写了。   
这时候我们需要一种辅助数据结构-```堆```，有了堆这个数据结构，难度等级是困难的题目，瞬间变成简单了。   
我们把三个链表一股脑的全放到堆里面
```
  1->4->5
  1->3->4
  2->6
```
然后由```堆```根据节点的```val```自动排好序   
![1.jpg](https://pic.leetcode-cn.com/83817b478b0aeb8de118c6e7676c437a7161a61aaf845e0d8633a08537077992-1.jpg)
这是一个```小根堆```，我们只需要每次输出```堆顶```的元素，直到整个堆为空即可。   
执行过程如下:
![2.jpg](https://pic.leetcode-cn.com/6a29e6a27232b5d42201b57c3ae9b256293b87a291f981c8a0f06e88e50c4379-2.jpg)


代码:
```java []
class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists==null || lists.length==0) {
			return null;
		}
		//创建一个堆，并设置元素的排序方式
		PriorityQueue<ListNode> queue = new PriorityQueue(new Comparator<ListNode>() {
			public int compare(ListNode o1, ListNode o2) {
				return (o1.val - o2.val);
			}
		});
		//遍历链表数组，然后将每个链表的每个节点都放入堆中
		for(int i=0;i<lists.length;i++) {
			while(lists[i] != null) {
				queue.add(lists[i]);
				lists[i] = lists[i].next;
			}
		}
		ListNode dummy = new ListNode(-1);
		ListNode head = dummy;
		//从堆中不断取出元素，并将取出的元素串联起来
		while( !queue.isEmpty() ) {
			dummy.next = queue.poll();
			dummy = dummy.next;
		}
		dummy.next = null;
		return head.next;
	}
}
```
```python []
class Solution:
	def mergeKLists(self, lists):
		if not lists:
			return None
		import heapq
		queue = []
		dummy = ListNode(-1)
		cur = dummy
		# 遍历链表数组，然后将每个链表的每个节点都放入堆中
		for i in xrange(len(lists)):
			head = lists[i]
			while head:
				heapq.heappush(queue,(head.val,head))
				head = head.next	
		# 从堆中不断取出元素，并将取出的元素串联起来
		while queue:
			_, cur.next = heapq.heappop(queue)
			cur = cur.next
		cur.next = None
		return dummy.next
```




## 堆排序的优化
首先看下下面这张图   
![3.jpg](https://pic.leetcode-cn.com/a91253f60b46b4d804adff9d3af7fb54586018e173d480cf06f4530630f3eb8d-3.jpg)
4个链表中的最小值，一定来自黄色的部分，黄色的部分就是一个```小根堆```。   
这个堆的元素个数是```k```个，也就是图中的```4```个。  
我们建立完```k```个大小的堆后，就不断的从堆中获取节点，如果获取到的```节点```不为空，即还有```下一个```节点，那么就将下一个节点放到堆中。利用这个特点我们就可以优化空间了，将原先的O(N)的空间复杂度优化到O(k)。 
这种场景就好像就是4个售票窗口(图中只有一个窗口，嗯，脑补下剩下三个。。。)，4排队伍在排队买票，但是只有一个工作人员，第一个人拿到票后，后面的人往前走，工作人员继续处理。   
![4.jpg](https://pic.leetcode-cn.com/c4892d7074883003ba000c59a3ff33c0c4dc3875491bcb8d11d25aa8301876a6-4.jpg)
动画演示如下:
![5.gif](https://pic.leetcode-cn.com/1d4fb6358f39ee7b4ad0b75119352a0fba44c550af0c310d594ae529717cbf3d-5.gif)


代码:
```java []
class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists==null || lists.length==0) {
			return null;
		}
		//创建一个小根堆，并定义好排序函数
		PriorityQueue<ListNode> queue = new PriorityQueue(new Comparator<ListNode>() {
			public int compare(ListNode o1, ListNode o2) {
				return (o1.val - o2.val);
			}
		});
		ListNode dummy = new ListNode(-1);
		ListNode cur = dummy;
		//这里跟上一版不一样，不再是一股脑全部放到堆中
		//而是只把k个链表的第一个节点放入到堆中
		for(int i=0;i<lists.length;i++) {
			ListNode head = lists[i];
			if(head!=null) {
				queue.add(head);
			}
		}
		//之后不断从堆中取出节点，如果这个节点还有下一个节点，
		//就将下个节点也放入堆中
		while(queue.size()>0) {
			ListNode node = queue.poll();
			cur.next = node;
			cur = cur.next;
			if(node.next!=null) {
				queue.add(node.next);
			}
		}
		cur.next = null;
		return dummy.next;
	}
}
```
```python []
class Solution:
	def mergeKLists(self, lists):
		if not lists:
			return None
		import heapq
		queue = []
		dummy = ListNode(-1)
		cur = dummy
		# 这里跟上一版不一样，不再是一股脑全部放到堆中
		# 而是只把k个链表的第一个节点放入到堆中
		for i in xrange(len(lists)):
			head = lists[i]
			if head:
				heapq.heappush(queue,(head.val,head))
		# 之后不断从堆中取出节点，如果这个节点还有下一个节点，
		# 就将下个节点也放入堆中
		while queue:
			_, head = heapq.heappop(queue)
			cur.next = head
			cur = cur.next
			if head.next:
				heapq.heappush(queue,(head.next.val,head.next))
		cur.next = None
		return dummy.next
```




## 两两合并
我们可以用合并两个链表的思路来合并k个链表，比如
```
A1
A2
A3
A4
```
对于这四个链表，我们先合并```A1```和```A2```，将这两个链表变成```A1-A2```，然后再按照两两合并的方式，合并```A1-A2```和```A3```，这三个链表就合并成了```A1-A2-A3```，最后将```A1-A2-A3```跟```A4```两两合并，四个链表就合并完了。    
![z.jpg](https://pic.leetcode-cn.com/a18aa5111445bc4b70adc7833bd31d14d7882ead9194e4304c0aaa44a55f92ad-z.jpg)
合并过程中，我们需要借用两两合并的代码，直接把下面这段代码拿来用即可。
```java
	public ListNode merge(ListNode a, ListNode b) {
		if(a==null || b==null) {
			return (a==null) ? b : a;
		}
		if(a.val<=b.val) {
			a.next = merge(a.next,b);
			return a;
		} else {
			b.next = merge(a,b.next);
			return b;
		}
	}
```
注:python的代码执行会超时！   

代码:
```java []
class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists==null || lists.length==0) {
			return null;
		}
		//将lists[0]作为最终合并的链表，然后将list[0]和lists[1]合并成lists[0-1]
		//再将lists[0-1]和lists[2]合并，如此反复最终lists[0]就是最终结果
		ListNode res = lists[0];
		for(int i=1;i<lists.length;i++) {
			res = merge(res,lists[i]);
		}
		return res;
	}
	
	//合并两个有序链表
	private ListNode merge(ListNode a, ListNode b) {
		if(a==null || b==null) {
			return (a==null) ? b : a;
		}
		if(a.val<=b.val) {
			a.next = merge(a.next,b);
			return a;
		} else {
			b.next = merge(a,b.next);
			return b;
		}
	}
}
```
```python []
class Solution(object):
	def mergeKLists(self, lists):
		if not lists:
			return None
		n = len(lists)
		res = lists[0]
		# 合并两个有序链表
		def merge(a,b):
			if not (a and b):
				return a if a else b
			if a.val<=b.val:
				a.next = merge(a.next,b)
				return a
			else:
				b.next = merge(a,b.next)
				return b
		# 将lists[0]作为最终合并的链表，然后将list[0]和lists[1]合并成lists[0-1]
		# 再将lists[0-1]和lists[2]合并，如此反复最终lists[0]就是最终结果
		for i in xrange(1,n):
			res = merge(res,lists[i])
		return res
```





## 分治
分治就是不断缩小其规模，再不断合并扩大的过程   
![6.jpg](https://pic.leetcode-cn.com/88d261465f1f21288dd23cef2f059297f5d053fc19805458a47ae1b05f3c0703-6.jpg)
一开始数组的规模是6，我们找到中间点，将起一分为二，然后再拆分，直到不能再拆分(规模为1时)时便返回。   
之后开始合并，合并的代码借用了```合并两个排序链表```的代码。   
当两个规模最小的链表合并完后，其规模就变大了，然后不断重复这个合并过程，直到最终得到一个有序的链表。   

代码:
```java []
class Solution {
	public ListNode mergeKLists(ListNode[] lists) {
		if(lists==null || lists.length==0) {
			return null;
		}
		return helper(lists,0,lists.length-1);
	}
	
	//通过mid将数组一分为二，并不断缩小规模，当规模为1时返回并开始合并
	//通过合并两个链表，不断增大其规模，整体看就是不断缩小-最后不断扩大的过程
	private ListNode helper(ListNode[] lists, int begin, int end) {
		if(begin==end) {
			return lists[begin];
		}
		int mid = begin+(end-begin)/2;
		ListNode left = helper(lists,begin,mid);
		ListNode right = helper(lists,mid+1,end);
		return merge(left,right);
	}
	
	//合并两个有序链表
	private ListNode merge(ListNode a, ListNode b) {
		if(a==null || b==null) {
			return (a==null) ? b : a;
		}
		if(a.val<=b.val) {
			a.next = merge(a.next,b);
			return a;
		} else {
			b.next = merge(a,b.next);
			return b;
		}
	}
}
```
```python []
class Solution(object):
	def mergeKLists(self, lists):	
		if not lists:
			return None
		# 通过mid将数组一分为二，并不断缩小规模，当规模为1时返回并开始合并
		# 通过合并两个链表，不断增大其规模，整体看就是不断缩小-最后不断扩大的过程
		def helper(begin,end):
			if begin==end:
				return lists[begin]
			mid = begin+(end-begin)/2
			left = helper(begin,mid)
			right = helper(mid+1,end)
			return merge(left,right)
		# 合并两个有序链表	
		def merge(a,b):
			if not (a and b):
				return a if a else b
			if a.val<=b.val:
				a.next = merge(a.next,b)
				return a
			else:
				b.next = merge(a,b.next)
				return b
		return helper(0,len(lists)-1)
```
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)