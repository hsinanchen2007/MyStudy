### 双指针解题思路
先判断head是否为空，不为空才能执行fast.next，不然报错：NoneType
while循环：
fast每次跳两格，slow每次跳一格，如果循环必然会相遇
fast跳两格前需验证fast.next是否为空

### 代码

```python
class Solution(object):
    def hasCycle(self, head):
        if not head:#判断head是否为空
            return False
        fast,slow = head.next,head
        while fast and slow:
            if fast == slow:
                return True
            if fast.next:
                fast = fast.next.next
            else:
                return False
            slow = slow.next
        return False
```

### 列表解题思路
构造列表set
遍历一个元素，加add（）一个
利用.next迭代下一个
当元素已经存在set中时，停止，return True

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        #定义一个列表set（）
        s = set()
        while head:
            if head in s:
                return True#如果遍历到一个元素已经存在，则有循环
            s.add(head)
            head = head.next
        return False
```