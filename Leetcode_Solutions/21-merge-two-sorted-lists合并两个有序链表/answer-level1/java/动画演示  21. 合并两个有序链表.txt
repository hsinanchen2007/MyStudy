# 题解
按照题目的要求，最终要把L1和L2两个链表合并成一个链表，实例图如下
![静态图_1.jpg](https://pic.leetcode-cn.com/cff71b0d4b6b532e662d3dcd7bbbb1ca47ce06bdde5e472d709b086e9a2403e8-%E9%9D%99%E6%80%81%E5%9B%BE_1.jpg)

我们要注意一种特殊的情况，链表L1为空，或者链表L2也为空，甚至L1和L2都是空
在面试的时候，碰到这种题目，第一时间在函数的入口处把边界条件处理了。
![静态图_2.jpg](https://pic.leetcode-cn.com/de6faa08abc0fdd96eb55579d2341ca540613b03ec944685c521c0284e87bcf1-%E9%9D%99%E6%80%81%E5%9B%BE_2.jpg)

这里用个三目表达式就可以搞定了
```python []
class Solution(object):
	def mergeTwoLists(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		if not (l1 and l2):
			return l1 if l1 else l2
    #...
```
```java []
class Solution {
	public ListNode mergeTwoLists(ListNode L1, ListNode L2) {
		//如果L1，L2有一个为空，直接返回就可以了
		//如果L1为空，返回L2(如果此时L2也是空就返回null)
		//如果L2不为空就返回L1
		if(L1==null || L2==null) {
			return (L1==null)? L2 : L1;
		}
		//...
	}
```
   
   
示例中的L1和L2两个链表一样长，但我们也要考虑到另外一种场景，L1和L2不一样长
![静态图_4.jpg](https://pic.leetcode-cn.com/f84d6a6ab92e7969032006f12773d6a20be236c9360a907bf6e30361e86be455-%E9%9D%99%E6%80%81%E5%9B%BE_4.jpg)

这种情况也好办，我们在合并链表的时候，就假设L1和L2是一样长的。等合并完之后，要不L1和L2都为空，要不就是L1和L2中的某一个不为空，我们只需要将合并完的链表尾巴指向那个不为空的L1或者L2就可以
![静态图_3.jpg](https://pic.leetcode-cn.com/b4e80daf360d2dd25944c6e0f3bc9321c28dc064ebda90b27339ec37a608105b-%E9%9D%99%E6%80%81%E5%9B%BE_3.jpg)


动态示例如下
![迭代版.gif](https://pic.leetcode-cn.com/64a575ae56a81ca7253edb32b2e96d8e5430404b8c933b7450b110e4068fde44-%E8%BF%AD%E4%BB%A3%E7%89%88.gif)


代码如下：
```java []
class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		ListNode p = new ListNode(-1);
		ListNode head = p;
		while(l1!=null && l2!=null) {
			//如果l1的值小于l2的值，就将p.next指向l1
			//然后l1继续往后移动一位
			if(l1.val<=l2.val) {
				p.next=l1;
				l1=l1.next;
			} else {
				p.next=l2;
				l2=l2.next; 
			}
			p=p.next;
		}
		//如果l1和l2不一样长，等遍历完后，将p的next指向没遍历完的链表即可
		//比如l1长度是3，1->2->3，l2长度是5 1->2->3->8->9
		//等循环结束时，l1就指向8->9，只要将p.next指向8->9即可
		p.next = (l1==null? l2:l1);
		return head.next;
	}
}
```
```python []
class Solution(object):
	def mergeTwoLists(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		#增加一个冗余的节点，方便后续处理
		p = ListNode(-1)
		head = p
		#这里的意思是l1!=null && l2!=null
		while l1 and l2:
			#如果l1的val<=l2的val，就将p指向l1
			#p.next,l1 = l1,l1.next这里是将两行合并了
			#只是为了代码简洁，面试时如果没有十足把握尽量分多行写
			if l1.val<=l2.val:
				p.next,l1 = l1,l1.next
			#else时，将p指向l2节点
			else:
				p.next,l2 = l2,l2.next
			p = p.next
		#这里是一个三目表达式，类似
		# l1==null? l2:l1
		# 如果l1不为空就将p.next指向l2
		# 如果l1为空就指向l2，如果l2也为空那就指向空
		p.next = l1 if l1 else l2
		return head.next
```

   
   
   	
# 递归版本
对于这道题，还有一个更骚气的递归解法，用递归的话，难度就陡增了，如果没有十足的把握尽量不要用递归，用上面那种迭代版本就可以了。
注意递归的三个条件：
终止条件：当`l1`或者`l2`中有一个为空时，就返回
函数内要做什么：如果`l1.val`小于`l2.val`，那么将`l1.next`指向 **l1的后续节点和l2中较小的一个**
终止条件比较好理解，函数内做的事情就不那么好懂了，这段话一定要明白：l1的后续节点和l2中较小的一个。    
`l1.val<=l2.val`后，我们就能确定一个较小的节点了，比如是`l1`。因为链表还没结束，我们要继续比较，这时候比较的是`l1.next`和`l2`。   
`l1.next`和`l2`是在下一层递归函数中处理的，再下一层函数中，也会确定一个较小的节点，我们将这个较小的节点记做`x`，然后上一层的`l1.next`就指向这个`x`节点。
后面就是不断的递归，最终把整个链表给串起来。 
     
递归的动态图如下，注意下图紫色的箭头，这是当整个链表遍历完时，达到了递归终止条件后，每一层的递归函数就不断的返回。   
于是下一层的节点就跟当前层的节点**串联**起来了。   
![递归版.gif](https://pic.leetcode-cn.com/4ba94519f9dc7692d7ce4fad3a815f2f6c6df44995ee5a34e3c896d37efe51ab-%E9%80%92%E5%BD%92%E7%89%88.gif)



代码实现如下：
```python []
class Solution(object):
	def mergeTwoLists(self, l1, l2):
		"""
		:type l1: ListNode
		:type l2: ListNode
		:rtype: ListNode
		"""
		#递归的结束点就是L1或者L2为空就返回
		#如果L1为空就返回L2，L2为空返回L1
		if not (l1 and l2):
			return l1 if l1 else l2
		#L1的val<=L2的val，那么继续递归
		#当前L1的next指向一个递归函数
		#意思是L1的下一个和L2哪个大，就作为当前L1的next
		if l1.val<=l2.val:
			l1.next = self.mergeTwoLists(l1.next,l2)
			return l1
		else:
			l2.next = self.mergeTwoLists(l1,l2.next)
			return l2
```
```java []
class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		//递归的结束条件，如果l1和l2中有一个为空就返回
		if(l1==null || l2==null) {
			return (l1==null)? l2:l1;
		}
		//如果l1的值<=l2的值，就继续递归，比较l1.next的值和l2的值
		//l1.next和l2比较完后，会产生一个更小的节点x，将x加到当前l1的后面
		if (l1.val<=l2.val) {
			l1.next = mergeTwoLists(l1.next,l2);
			return l1;
		//如果l1的值>l2的值，就继续递归，比较l1的值和l2.next的值
		} else {
			l2.next = mergeTwoLists(l1,l2.next);
			return l2;
		}
	}
}
```
(全文完)   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)
