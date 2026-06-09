### 解题思路
1.迭代：这个思路简单，通过队列存储，除最后一个不为空的节点。然后依次pop()进行头插法的方式重绘链表

2.递归：这个思路也采用头插法的方式，建立头节点副本，用于递归中目标插入节点。匹配到最后一个不为空的节点，再建立一个副本，用于作为递归中的当前节点，以此实现头插法。

注：关键点在于每次递归后，参数值是上一次，递归前的数值，因此如果保存每次递归的值需要手动return temp。


3.双指针：这个思路在于每次构造一个新的节点对象反向指向前一个节点。相当于重新方向构造了一个链表。链表的头结点为None




### 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

from collections import deque
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        
        # 利用队列实现迭代算法
        if not head:
            return None
        deq = deque()
        while head.next:
            deq.append(head)
            head = head.next
        # 此时head指向最后一个不为空的节点
        temp = head
        while deq:
            node = deq.pop()
            node.next = temp.next
            temp.next = node
            temp = node
        return head
        
    
        
```
```python
class Solution:
    def move_single(self,head,temp):
        # 这里不能用val代替对象来进行条件判断，除非规定所有val都不同，所以比较两个节点的对象
        if head.next != temp:
            # 递归不会覆盖之前的数据，类似回复现场，因此要手动替换temp
            temp = self.move_single(head.next,temp)
        head.next = temp.next
        temp.next = head
        temp = head
        return temp
       
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # 递归算法
        if not head:
            return None
        if not head.next:
            return head
        temp = head
        while temp.next:
            temp = temp.next
        # 此时temp到达了最后一个不为空的节点
        result = temp
        self.move_single(head,temp)
        return result
```


```python
    # 双指针，一个指针用作新生成的一个链表当前节点，另一个指针用于源链表遍历
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        pre = head
        cur = None
        while pre:
            # 这个临时节点就相当于一个副本
            temp = ListNode(pre.val)
            temp.next = cur
            cur = temp
            pre = pre.next
        return cur
```