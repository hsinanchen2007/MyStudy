### 解题思路
通过set来找到相交位置。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        sa = set()
        sb = set()
        if not headA or not headB:
            return None 

        while (headA or headB) and headA not in sb and headB not in sa: 
            
            if headA:
                sa.add(headA)
            if headB:
                sb.add(headB)

            if headB in sa:
                return headB
            elif headA in sb:
                return headA
        
            if headA:
                headA = headA.next
            if headB:
                headB = headB.next

        if headB in sa:
            return headB
        elif headA in sb:
            return headA


        
        return None

```


### 解题思路
然后我们定义两个指针，一个从a链表头出发，一个从b链表头出发，因为是环形的，最终两个链表会相遇，而相遇的节点就是相交的节点。

### 代码

```python
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