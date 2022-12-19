# 利用数组
首先我们来解释下，什么叫回文。把相同的词汇或句子，在下文中调换位置或颠倒过来，产生首尾回环的情趣，叫做回文，也叫回环。因为正反都一样，意味着以一个中间节点为基准，一个指针从开头往中间走，另一指针走结尾往中间走，两个指针不断遍历比较的结果应该是一样的。   
比如下面这个字符串:   
```
1234321
```
上图中的中间点是4，所以分割完后，再将后半部分颠倒
```
123
123
```
所以这个字符串就是回文串。   
对于链表我们可以这么做：   
将所有元素放到一个数组中，再利用双指针迭代比较元素中的内容   
![1571891315(1).jpg](https://pic.leetcode-cn.com/69a4fd802c249fb9dbb5ff13abee10e9b0a1251a9679d4c31d7f9c3defb2402c-1571891315\(1\).jpg)
两个指针不断往中间迭代比较   
![1571891325(1).jpg](https://pic.leetcode-cn.com/985ef83e07b9807454246e5065c1f52001f4431d15d49ffcdb40c7ab46de25df-1571891325\(1\).jpg)
   
代码实现：   
```java []
class Solution {
	public boolean isPalindrome(ListNode head) {
		if(head==null || head.next==null) {
			return true;
		}
		java.util.ArrayList<Integer> arr = new java.util.ArrayList<Integer>();
		//申请一个容器，然后把元素都放到数组中
		while(head!=null) {
			arr.add(head.val);
			head = head.next;
		}
		int i = 0;
		int j = arr.size()-1;
		//用i和j两个指针，一个往后，一个往前，不断迭代
		//如果i的值不等于j说明不是回文，反之是回文
		while(i<j) {
			if(arr.get(i).compareTo(arr.get(j))!=0) {
				return false;
			}
			++i;
			--j;
		}
		return true;
	}
}
```
```python []
class Solution(object):
	def isPalindrome(self, head):
		"""
		:type head: ListNode
		:rtype: bool
		"""		
		if not (head and head.next):
			return True
		arr,i = [],0
		# 申请一个数组，然后把元素都放到数组中
		while head:
			_,head = arr.append(head.val),head.next
		j = len(arr)-1
		# 用i和j两个指针，一个往后，一个往前，不断迭代
		# 如果i的值不等于j说明不是回文，反之是回文
		while i<j:
			if arr[i]!=arr[j]:
				return False
			i,j = i+1,j-1
		return True
```

# 双指针+反转
我们利用链表的两个操作：      
1. 找到链表的中间节点
2. 反转链表   

通过这两个操作之后，原链表就以中间节点被一分为二   
前半部分一个链表，后半部分(被反转了)为一个链表   
然后遍历这两个链表，如果遍历过程中发现两个链表节点不同，就说不是回文链表，直接返回false即可   
如果链表遍历完了，说明是回文链表   
注意一个小细节，如果链表长度是偶数的话，前半部分和后半部分长度是一样的   
如果链表长度是奇数，那么前半部分的长度比后半部分长度多1个   
所以最后迭代链表的时候，以后半部分为准就可以了，当链表总长为奇数时，前半部分的最后一个节点就不会被遍历到了。   
![1571891335(1).jpg](https://pic.leetcode-cn.com/8bb8e8bd331754840bc366341598e91456005f69bade3ed5e279142b95086ccb-1571891335\(1\).jpg)
动态如如下：   
![回文链表-动态图.gif](https://pic.leetcode-cn.com/5781a82fcd49c3ee8341f7a0dc801d4924f8e6daa994455cf348c13fd7903321-%E5%9B%9E%E6%96%87%E9%93%BE%E8%A1%A8-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)

代码实现:      
```java []
class Solution {
	public boolean isPalindrome(ListNode head) {
		//边界条件不用忘记了
		if(head==null || head.next==null) {
			return true;
		}
		ListNode p = new ListNode(-1);
		ListNode low = p;
		ListNode fast = p;
		p.next = head;
		//快慢指针不断迭代，找到中间节点
		while(fast!=null && fast.next!=null) {
			low = low.next;
			fast = fast.next.next;
		}
		ListNode cur = low.next;
		ListNode pre = null;
		low.next = null;
		low = p.next;
		//将链表一分为二之后，反转链表后半部分
		while(cur!=null) {
			ListNode tmp = cur.next;
			cur.next = pre;
			pre = cur;
			cur = tmp;
		}
		//将链表前半部分和 反转的后半部分对比
		while(pre!=null) {
			if(low.val!=pre.val) {
				return false;
			}
			low = low.next;
			pre = pre.next;
		}
		return true;
	}
}
```
```python []
class Solution(object):
	def isPalindrome(self, head):
		"""
		:type head: ListNode
		:rtype: bool
		"""
		# 边界条件不用忘记了
		if not (head and head.next):
			return True
		p = ListNode(-1)
		p.next,low,fast = head,p,p
		# 快慢指针不断迭代，找到中间节点
		while fast and fast.next:
			low,fast = low.next, fast.next.next
		cur,pre = low.next,None
		low.next = None
		#将链表一分为二之后，反转链表后半部分
		while cur:
			cur.next,pre,cur = pre,cur,cur.next
		a,b = p.next,pre
		# 将链表前半部分和 反转的后半部分对比
		while b:
			if a.val!=b.val:
				return False
			a,b = a.next,b.next
		return True
```
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)