
# 题解
我们不断的遍历两个链表，每次遍历都将链表a和链表b的值相加，再赋给链表a。如果有进位我们还需要记录一个进位标志。   
循环的条件是链表a不为空或者链表b不为空，这样当整个循环结束时，链表就被串起来了。   
当循环结束时，如果进位标志>0还需要处理下边界条件。   
我们不用生成一个新的节点，直接将两个节点相加的值赋给节点a就可以了，这样只用改变节点的内容，速度会更快一些。   
![迭代.gif](https://pic.leetcode-cn.com/9f326746800ef8b13ee6bac7bf5154356cb9d99f623364773be4d7fc01259ef4-%E8%BF%AD%E4%BB%A3.gif)
  
    
代码实现：
```java []
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode p = null;
		ListNode a = l1;
		ListNode b = l2;
		//定义一个进位标志
		int carry = 0;
		while(a!=null || b!=null) {
			//a和b节点的值相加，如果有进位还要加上进位的值
			int val = (a==null?0:a.val) + (b==null?0:b.val) + carry;
			//根据val判断是否有进位
			carry = val>=10? 1:0;
			//不管有没有进位，val都应该小于10
			val = val%10;
			p = (a==null? b : a);
			p.val = val;
			//a和b指针都前进一位
			a = (a==null? null : a.next);
			b = (b==null? null : b.next);
			//根据a和b是否为空，p指针也前进一位
			p.next = (a==null? b : a);
		}
		//不要忘记最后的边界条件，如果循环结束carry>0说明有进位需要处理这个条件
		if(carry>0) {
			p.next = new ListNode(1);
		}
		//每次迭代实际上都是将val赋给a指针的，所以最后返回的是l1
		return l1;
	}
}
```
```python []
class Solution(object):
	def addTwoNumbers(self, l1, l2):
		# 定义一个进位标志
		a,b,p,carry = l1,l2,None,0
		while a or b:
			# a和b节点的值相加，如果有进位还要加上进位的值
			val = (a.val if a else 0)+(b.val if b else 0)+carry
			# 根据val判断是否有进位,不管有没有进位，val都应该小于10
			carry,val = val/10 if val>=10 else 0,val%10
			p,p.val = a if a else b,val
			# a和b指针都前进一位
			a,b = a.next if a else None,b.next if b else None
			# 根据a和b是否为空，p指针也前进一位
			p.next = a if a else b
		# 不要忘记最后的边界条件，如果循环结束carry>0说明有进位需要处理这个条件	
		if carry:
			p.next = ListNode(carry)
		# 每次迭代实际上都是将val赋给a指针的，所以最后返回的是l1	
		return l1
```
   
   
   
# 递归实现
写递归的时候注意递归函数的两个条件，递归出口条件，以及函数内要做什么。   
1. 递归出口条件：链表a和链表b都为空时   
2. 将两个链表的值相加，再赋给链表a   
   
这里需要注意第二个条件，因为进位标志需要通告下一层递归函数，所以需要有一个单独的变量作为记录。   
函数内部的进位标志判断，val计算的方式和迭代版本是类似的。   
调用下一层递归的时候，传递的参数是a.next和b.next。   
这里还需要注意一个细节，如果a，b两个链表不一样长，意味递归到一定的层次时，某个链表会出现null，这时需要做一个补0的操作，创建一个新的节点赋给节点为空的链表。这也是为什么递归函数的终止条件是a和b都==null的原因。   
![递归.gif](https://pic.leetcode-cn.com/b8167f09861055f1f2fa8c4aa11e185b4f92a8d488e7de76e9c8609adaa42e1e-%E9%80%92%E5%BD%92.gif)
   
   
代码实现：
```java []
class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		return add(l1,l2,0);
	}

	ListNode add(ListNode a, ListNode b, int carry) {
		//递归的终止条件是a和b都为空
		//如果carry大于0需要返回一个进位标志
		if(a==null && b==null) {
			return (carry>0 ? new ListNode(1): null);
		}
		//如果a为空则将ListNode(0)赋给a，对于b也是
		a = (a==null? new ListNode(0) : a);
		b = (b==null? new ListNode(0) : b);
		//处理val，以及进位标志
		int val = a.val+b.val+carry;
		carry = (val>=10? 1 : 0);
		val %= 10;
		a.val = val;
		//现在a的值就是两个节点相加后的和了
		//之后再次递归计算a.next和b.next
		a.next = add(a.next,b.next,carry);
		return a;
	}
}
```
```python []
class Solution(object):
	def addTwoNumbers(self, l1, l2):
		# 主要逻辑都在内部函数中实现
		def add(a,b,carry):
			# 递归的终止条件是a和b都为空
			# 如果carry大于0需要返回一个进位标志
			if not (a or b):
				return ListNode(1) if carry else None
			# 如果a为空则将ListNode(0)赋给a，对于b也是
			a = a if a else ListNode(0)
			b = b if b else ListNode(0)
			#处理val，以及进位标志
			val = a.val + b.val + carry
			carry = 1 if val>=10 else 0
			a.val = val%10
			# 现在a的值就是两个节点相加后的和了
			# 之后再次递归计算a.next和b.next
			a.next = add(a.next,b.next,carry)
			return a
		return add(l1,l2,0)
```
(全文完)
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)