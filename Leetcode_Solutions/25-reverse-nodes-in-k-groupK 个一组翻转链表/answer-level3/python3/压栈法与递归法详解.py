题目要求K个一组翻转链表，共有 n 组节点需要执行单链表翻转动作，其中 n 与链表长度有关，所以初步考虑可以使用递归算法来做。

#### 解法一：递归算法

分析认为考察了两个知识点：
  - 对链表翻转算法的掌握
  - 对递归算法的使用

递归思路：
  - 将给定的链表根据 K 进行分组
  - 每组组内进行单链表翻转
  - 将翻转后的节点关联到后续节点

```
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        curr, count = head, 0
        
        # 遍历链表，找到分组节点
        while count != k and curr:
            curr = curr.next
            count += 1
        if count == k:
            # 递归
            curr = self.reverseKGroup(curr, k)
            while count > 0:
                # 用 temp 暂存待翻转的值
                temp = head.next
                # 先关联上后续链表节点
                head.next = curr
                # 将当前结果存入curr变量，以便对head变量进行后续操作
                curr = head
                # 用 head 继续处理待翻转的值
                head = temp
                count -= 1
            head = curr

        return head
```

#### 解法二：用栈的先进后出特性实现翻转

分析：
  - 栈的特性是先进后出，对于 k 个一组的链表来说，对每组数据进行一次入栈和出栈，即完成了翻转工作
  - 最后一组如何不满足 k 个，则需要反向出栈来完成（比较浪费性能）
  - 入栈和出栈操作对时间复杂度不是很友好，所以此解法主要看看思路就好

```
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if head == None or head.next == None:
            return head

        # 定义一个栈，用来存放要翻转的数据
        stack = []
        # 定义一个dummy节点，便于对链表进行操作
        dummy = ListNode(0)
        
        curr, dummy.next = head, head
        temp = dummy

        while curr:
            # 入栈
            stack.append(curr)
            curr = curr.next
            # 栈内元素达到一组（也就是k个），出栈并挂到新链表中
            if len(stack) == k:
                while stack:
                    temp.next = stack.pop()
                    temp = temp.next
        while stack:
            temp.next = stack.pop(0)
            temp = temp.next
        
        return dummy.next
```

