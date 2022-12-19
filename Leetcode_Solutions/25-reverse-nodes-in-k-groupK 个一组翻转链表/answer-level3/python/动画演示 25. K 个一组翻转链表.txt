## 题解一
有一道经典的题目，反转链表，将```1->2->3->4```变成```4->3->2->1```。反转链表的一个解法是用栈作为辅助结构，将```[1,2,3,4]```放入栈中，然后依次弹出来，再把弹出来的节点串联起来，这样就变成```4->3->2->1```了。   
对于```k```个一组反转，我们也可以用同样的方式，只不过这次不是将全部节点放入栈中，而是将```k```个节点放入栈中，之后再弹出```k```个节点，并将他们依次串联起来，这样就达到了反转```k```个节点的效果了。     
![1.jpg](https://pic.leetcode-cn.com/eb5ba70680ff11a9d47bc5af6a093725cf3e9e3aa672da6ff13d1117be89db7f-1.jpg)
有个细节需要注意下，比如链表是:   
```1->2->3->4->5->6->7```，```k=3```时，整个链表遍历完后，栈的个数不等于k，此时栈中只有一个元素```7```。   
这也简单，只要判断下```栈长度```不等于```k```直接退出就可以了。   
当然用栈实现其实并不符合题意，只当扩展下思路。 

代码实现:
```java []
class Solution {
	public ListNode reverseKGroup(ListNode head, int k) {
		if(head==null || k<=0) {
			return head;
		}
		//用栈来保存链表的节点
		Stack<ListNode> stack = new Stack<ListNode>();
		ListNode dummy = new ListNode(-1);
		dummy.next = head;
		ListNode p = dummy;
		int n = k;
		while(p!=null && p.next!=null) {
			ListNode tmp = p.next;
			//不断的将节点加入到栈中
			while(tmp!=null && n>0) {
				stack.add(tmp);
				tmp = tmp.next;
				--n;
			}
			//栈中的第一个元素，就是原链表中的第k个
			//这里备份第k+1个节点，用作后面串联用
			ListNode nextNode = stack.peek().next;
			//n==0说明栈中正好存了k个元素，挨个弹出来并串联起来
			//否则就退出循环
			if(n==0) {
				while(stack.size()>0) {
					p.next = stack.pop();
					p = p.next;
				}
			} else {
				break;
			}
			//假设链表是1->2->3->4->5，k=3
			//栈的内容是[3,2,1]，栈中第一个元素的next就是4
			//于是将p.next指向4就可以了
			p.next = nextNode;
			n = k;
		}
		return dummy.next;
	}
}
```
```python []
class Solution(object):
	def reverseKGroup(self, head, k):
		if not head or k<=0:
			return head
		# 用栈来保存链表的节点	
		stack = []
		dummy = ListNode(-1)
		dummy.next = head
		p = dummy
		n = k
		while p and p.next:
			tmp = p.next
			# 不断的将节点加入到栈中
			while tmp and n>0:
				stack.append(tmp)
				tmp = tmp.next
				n -= 1
			# 栈中的第一个元素，就是原链表中的第k个
			# 这里备份第k+1个节点，用作后面串联用
			next_node = stack[-1].next
			# n==0说明栈中正好存了k个元素，挨个弹出来并串联起来
			#否则就退出循环
			if n==0:
				while stack:
					p.next = stack.pop()
					p = p.next
			else:
				break
			#假设链表是1->2->3->4->5，k=3
			# 栈的内容是[3,2,1]，栈中第一个元素的next就是4
			# 于是将p.next指向4就可以了
			p.next = next_node
			n = k
		return dummy.next
```




## 题解二
只要反转链表弄懂了，反转k个也就不难理解了。   
这里我们需要借用反转链表的代码:   
```java []
	public ListNode reverseList(ListNode head) {
		ListNode pre = null;
		ListNode cur = head;
		ListNode tmp = null;
		while(cur!=null) {
			tmp = cur.next;
			cur.next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
```
反转链表的动态演示如下:   
![2.gif](https://pic.leetcode-cn.com/241f3e573d668eaf19555cda1a81b827accdd32c31696c99ac7ad60b6d9049c4-2.gif)
现在我们是反转```k```个，于是就遍历```k```个链表，然后将第```k```个节点的next指向空(防止循环)，这样就得到了长度为```k```的单链表了。   
之后我们将长度为```k```的链表直接交由```反转链表```函数处理，于是我们就可以得到长度为```k```的反转链表了。   
![3.jpg](https://pic.leetcode-cn.com/8b52f7774f04f5b1357200894f39c5b923750e97c809ac9d96658e192c2095e9-3.jpg)
如果遍历完整个链表，发现最后几个节点的长度不足```k```，那么直接退出就可以了。   
反转的时候需要注意，把长度```k```的链表前后指向切断，这样就不会出现循环指向了。   
![4.gif](https://pic.leetcode-cn.com/019a39a8fc9fcf8359dc5cb46792fb45177430a781629f49df0aa54ff152c428-4.gif)

代码实现:
```java []
class Solution {
	public ListNode reverseKGroup(ListNode head, int k) {
		if(head==null || k<=0) {
			return head;
		}
		ListNode dummy = new ListNode(-1);
		dummy.next = head;
		ListNode p = dummy;
		int n = k;
		//增加一个哨兵节点，之后不断遍历链表
		while(p.next!=null)  {
			ListNode tmp = p;
			//遍历得到k个长度的链表
			while(tmp!=null && tmp.next!=null && n>0) {
				tmp = tmp.next;
				--n;
			}
			//如果k==0说明符合条件，就反转这一组链表
			//反转之前需要将下一个节点保存，并设置next为空，防止循环指向
			//假设链表为1->2->3->4，下面的nextNode就是4，tail是1
			if(n==0) {
				ListNode nextNode = tmp.next;
				ListNode tail = p.next;
				tmp.next = null;
				p.next = reverse(tail);
				tail.next = nextNode;
				p = tail;
				n = k;
			//如果遍历后的链表长度不是k，则不满足反转条件	
			} else {
				break;
			}
		}
		return dummy.next;
	}
	//反转单个链表
	private ListNode reverse(ListNode head) {
		ListNode cur = head;
		ListNode pre = null;
		while(cur!=null) {
			ListNode tmp = cur.next;
			cur.next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}
}
```
```python []
class Solution(object):
	def reverseKGroup(self, head, k):
		if not head or k<=0:
			return head
		dummy = ListNode(-1)
		p,dummy.next = dummy,head
		n = k
		# 反转单个链表
		def reverse(head):
			pre,cur = None,head
			while cur:
				cur.next,pre,cur = pre,cur,cur.next
			return pre
		# 增加一个哨兵节点，之后不断遍历链表	
		while p.next:
			tmp = p
			# 遍历得到k个长度的链表
			while tmp and tmp.next and n>0:
				tmp = tmp.next
				n -= 1
			# 如果k==0说明符合条件，就反转这一组链表
			# 反转之前需要将下一个节点保存，并设置next为空，防止循环指向
			# 假设链表为1->2->3->4，下面的nextNode就是4，tail是1
			if n==0:
				next_node = tmp.next
				tail = p.next
				tmp.next = None
				p.next = reverse(tail)
				tail.next = next_node
				p = tail
				n = k
			# 如果遍历后的链表长度不是k，则不满足反转条件	
			else:
				break
		return dummy.next
```
(全文完)
   
**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)


