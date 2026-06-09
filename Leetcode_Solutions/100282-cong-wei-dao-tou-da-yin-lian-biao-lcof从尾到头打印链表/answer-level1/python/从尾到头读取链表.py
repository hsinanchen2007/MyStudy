### 解题思路
# 两个大方向：
# 一、利用栈后入先出的特性：
步骤：
1. 循环入栈：数组实现
2. 出栈：因为python的栈是由列表实现的，所以有两种方法可以实现列表元素的反转
- 列表逆向读取：
```python [1]
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []

        while head != None:
            stack.append(head.val)
            head = head.next
        stack.reverse()
        
        return stack
```
```python [2]
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []

        while head != None:
            stack.append(head.val)
            head = head.next
        
        return stack[::-1]
```

时间复杂度：O(N)
空间复杂度：O(N)

- 借助辅助栈：
```
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []
        result = []

        while head != None:
            stack.append(head.val)
            head = head.next
        
        while stack:
            result.append(stack.pop())
        
        return result
```

时间复杂度：O(2N)
空间复杂度：O(N) stack和result共用O(N)的空间


# 二、利用递归：
在打印当前元素之前，先打印后一个元素，也即：对下一个元素重复调用该函数
```python [1]
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []

        if not head:
            return []
        else:
            return self.reversePrint(head.next) + [head.val]
```
```python [2]
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        stack = []

        return self.reversePrint(head.next) + [head.val] if head else []
```
时间复杂度：O(N)
空间复杂度：O(N)
