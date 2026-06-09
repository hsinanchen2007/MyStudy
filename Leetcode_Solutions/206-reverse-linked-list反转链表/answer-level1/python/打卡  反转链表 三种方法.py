### 解题思路
递归（recursion）：递归常被用来描述以自相似方法重复事物的过程，在数学和计算机科学中，指的是在函数定义中使用函数自身的方法。（A调用A）
迭代（iteration）：重复反馈过程的活动，每一次迭代的结果会作为下一次迭代的初始值。（A重复调用B）

### 方法一：简易取巧--只改数值，不改结构
```python
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 取巧方法,直接改值
        head_ = head
        List = []
        while head_:
            List.append(head_.val)
            head_ = head_.next
        head_ = head
        i = -1
        while head_:
            head_.val = List[i]
            head_ = head_.next
            i-=1
        return head
```


### 方法二：递归

```python
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 递归 recursion
        head_ = head 
        # 注意空链表
        # 如果链表为空链表或单元素链表，初始状态x->null
        if not head or not head.next:
            return head
        # 递归过程，每次输出链表的最后一位，指向当前输入
        recur_head = self.reverseList(head_.next)
        head.next.next = head_
        head_.next = None
        return recur_head
```

### 方法三 迭代
```python
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 迭代 iteration
        head_ = head
        connect = None
        # head_->1 1->None;head_->2 2->1;...head_->5 5->4
        while head_:
            lastNode = head_.next
            head_.next = connect
            connect = head_
            head_ = lastNode
        # connect记录链表head_的前一位
        return connect
```

