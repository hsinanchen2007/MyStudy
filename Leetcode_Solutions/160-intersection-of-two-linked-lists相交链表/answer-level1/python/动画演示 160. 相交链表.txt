
# 利用set实现

我们先遍历链表a，将a链表的所有节点放入一个set中。   
之后再遍历b链表，如果b链表的某个节点出现在set中，那么就找到了第一个相交的节点 java实现   
```java []
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set s = new HashSet();
        ListNode p = headA;
        ListNode q = headB;
        //定义一个set之后，不断遍历p链表，然后将所有元素加入到set中
        while(p!=null) {
            s.add(p);
            p = p.next;
        }
        while(q!=null) {
            //遍历q链表，如果q链表的元素出现在set中，
            //重合，而这个重合的就是第一个相交的节点就说明
            //p和q两个链表有
            if(s.contains(q)) {
                return q;
            }
            q = q.next;
        }
        return null;
    }
}
```
```python []
class Solution(object):
	def getIntersectionNode(self, headA, headB):
		"""
		:type head1, head1: ListNode
		:rtype: ListNode
		"""
		s,p,q = set(),headA,headB
		#定义一个set之后，不断遍历p链表，然后将所有元素加入到set中
		while p:
			_,p = s.add(p),p.next
		while q:
			#遍历q链表，如果q链表的元素出现在set中，
			#就说明p和q两个链表有重合，
			#而这个重合的就是第一个相交的节点
			if q in s:
				return q
			q = q.next
		return None
```
这种方式可以解决问题，但是明显不符合题目要求，题目要求是空间复杂度为O(1)，这里创建了一个Set，空间复杂度就变成了O(n)。   
下面我们来看看如何用O(1)的时间复杂度来解决这个问题。   
      
      
   
# 双指针方式
这道题其实跟 141.环形链表 有点类似，环形链表中题目已经明确说链表是有环的。而这道题只是说了两个链表有相交的节点，那么我们可以改变一下链表的结构，人为的将这个链表变成环形。   
我们可以将a和b两个链表强行串联起来，变成一个8字的形状。   
原结构如下：   
![1571538456(1).jpg](https://pic.leetcode-cn.com/ea1e074623acfc0c693bf9ac47f556a9a2500b8503d8bb6f6f6a4bfec064aa45-1571538456\(1\).jpg)

我们将b链表的尾巴指向a节点的头部，将a节点的尾巴指向b链表的头部      
![1571538464(1).jpg](https://pic.leetcode-cn.com/6d24c0d2f451f8cfccea0edaff474d5d1e834d2199272974915d80e332f5fb50-1571538464\(1\).jpg)
   
然后我们定义两个指针，一个从a链表头出发，一个从b链表头出发，因为是环形的，最终两个链表会相遇，而相遇的节点就是相交的节点   
![动态图.gif](https://pic.leetcode-cn.com/396526c47e043feb977e59f98d8df9165ae249d5042ca60ee4d3121c05fea067-%E5%8A%A8%E6%80%81%E5%9B%BE.gif)
   
代码实现
```java []
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        //定义了两个节点a和b，只要a和b不等就继续遍历
        while(a!=b) {
            //这步很关键，请对照动态图配合理解，当a的下一个为空时，
            //就a就从b链表头开始遍历
            a = (a!=null)? a.next : headB;
            //同理，b也是类似的
            b = (b!=null)? b.next : headA;
        }
		return a;
    }
}
```
```python []
class Solution(object):
	def getIntersectionNode(self, headA, headB):
		"""
		:type head1, head1: ListNode
		:rtype: ListNode
		"""
		a,b = headA,headB
		# 定义了两个节点a和b，只要a和b不等就继续遍历
		while a!=b:
			# 这步很关键，请对照动态图配合理解，
			#当a的下一个为空时，就a就从b链表头开始遍历
			a = a.next if a else headB
			# 同理，b也是类似的
			b = b.next if b else headA
		return a
```   
(全文完)   

**如果你觉得本文对你有帮助，欢迎关注我的公众号。**
   
![ban.png](https://pic.leetcode-cn.com/6b52b8de211ec9b634d7aaf6ccf2d9149160ca3b67ea0742c57f622f1c54e47d-ban.png)