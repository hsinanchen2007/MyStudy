### 1.python数组存储逆序输出
![image.png](https://pic.leetcode-cn.com/6b2201c440a58e8ed9f6b2b54659942f553b19dad74869d21b7f17b5488a41b8-image.png)
- 从头到尾遍历链表,同时将每一个元素存在一个`list`中,最后在逆序输出.逆序输出可以使用`[::-1]`或者`reverse()`函数
- 时间复杂度`O(n)`,空间复杂度`O(n)`

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reversePrint(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        result = []
        while head:
            result.append(head.val)
            head = head.next
        return result[::-1]
```
### 2.借助辅助栈
![image.png](https://pic.leetcode-cn.com/9f410b07e5a5181afe2e9bce674b5673cec90acb559f701cad47556c68c3ece7-image.png)
- 我们知道栈的原理是先进后出,题目要求我们逆序输出,刚好能利用栈的特性
- 遍历链表,并使用辅助栈`stack`来保存节点值,最后将元素一个一个的从栈顶拿出就是我们要的结果
- 时间复杂度`O(n)`,空间复杂度`O(n)`
### 代码
```
class Solution(object):
    def reversePrint(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        stack = []
        result = []
        while head:
            stack.append(head.val)
            head = head.next
        while stack:
            result.append(stack.pop())
        return result
```
### 3.递归实现
![image.png](https://pic.leetcode-cn.com/7401a2c4193997e6219858c33157959bad48b324065ecbf061f58a617a2ca07b-image.png)

- 有了使用辅助栈的思路,不难想到其实递归本质上就是一个栈的结构
- 递归遍历到节点尾部,在回退的时候再保存节点值即可
- 时间复杂度`O(n)`,空间复杂度`O(n)`

### 代码
```
class Solution(object):
    def reversePrint(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        result = []
        def solution(head):
            if head:
                solution(head.next)
                result.append(head.val)
        solution(head)
        return result  
```

