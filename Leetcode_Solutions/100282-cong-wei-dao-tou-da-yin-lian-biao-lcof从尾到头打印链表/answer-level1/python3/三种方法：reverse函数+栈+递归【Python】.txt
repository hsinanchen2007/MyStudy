### 思路

##### 解法一

**reverse函数**

**时间复杂度:** O(n)，n为 head 链表长度。
**空间复杂度:** O(n)，n为 head 链表长度。

##### Python3代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        # solution one: reverse
        res = []
        while head:
            res.append(head.val)
            head = head.next
        res.reverse()
        return res
```

##### 解法二

**栈**

**时间复杂度:** O(n)，n为 head 链表长度。
**空间复杂度:** O(n)，n为 head 链表长度。

##### Python3代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        # solution two: 栈
        stack = []
        while head:  # push
            stack.append(head.val)
            head = head.next
        res = []
        while stack:  # pop
            res.append(stack.pop())
        return res
```

##### 解法三

**递归**

##### Python3代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        # solution three: 递归
        return self.reversePrint(head.next) + [head.val] if head else []
```

### 代码地址

[GitHub链接](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/Interview-06-cong-wei-dao-tou-da-yin-lian-biao-lcof/06.py)