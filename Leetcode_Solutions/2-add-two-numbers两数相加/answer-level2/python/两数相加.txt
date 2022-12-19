# Leetcode(2) - 两数相加

> 更多可以查看我的博客：http://bonky.top

**问题描述：**

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 **一位** 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

首先现附上代码：

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
  def situation(self, l1, l2, carry):
    if l1 == None and l2 == None:
      return (None, carry)
    
    if l1 == None:
      return (l2, carry)
    
    if l2 == None:
      return (l1, carry)
    
    if l1.val + l2.val+ carry >= 10:
      self.ans.next = ListNode(l1.val + l2.val+ carry - 10)
      self.ans = self.ans.next
      return self.situation(l1.next, l2.next, 1)
    
    else:
      self.ans.next = ListNode(l1.val + l2.val+ carry)
      self.ans = self.ans.next
      return self.situation(l1.next, l2.next, 0)

  def addcarry(self, l, carry): 
    sum = l.val + carry
    if sum == 10:
      l.val = 0
      if l.next == None:
        l.next = ListNode(1)
        return
      else:
        self.addcarry(l.next, 1)
    else:
      l.val = sum
    
  def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
    head = ListNode(None)
    self.ans = ListNode(None)
    head.next = self.ans
    node,carry = self.situation(l1, l2, 0)
    
    if node == None and carry == 1:
      self.ans.next = ListNode(1)
    elif node == None and carry == 0:
      pass
    else:
      self.ans.next = node
      self.addcarry(node, carry)
      
    return head.next.next
```

我的思路其实很简单，`situation` 函数直接遍历，直到遍历完最短的链表，把公共部分加完为止，得到一个和公共部分等长的链表 `l`，然后最后考虑把长的链表的剩余部分直接连接在 `l` 的后面，最后再考虑进位和剩余串的问题，我们利用`addcarry`函数给剩余串进位。

其实这道题就重要的是要对所有情况的考虑。处理`carry` 的进位是主要考虑的因素。

首先是`situation`函数，函数返回值有两个：`node` 和`carry`。`node` 的作用是返回需要接在公共串后面的链表，`carry `的作用是保存公共串最后的进位。这里用了递归的方法。

对于返回值，我们需要把三种情况分开考虑：

- `l1` 和 `l2` 一样长，或者都为空，那么返回的的`node=None`，
- `l1`长，`l2`先为空。那么返回的的`node=l1 `，
- `l2`长，`l1`先为空。那么返回的的`node=l2 `，

`addarray` 我们也需要考虑三种情况

- `l` 和 `carry` 和为10，先设置为0（因
- 为和只能为10，10-10=0）：
  - 如果 `l` 的下一个数为空，那么我们要再建立一个为1的结点，结束
  - 否则，我们将进位传给 `l` 的下一位，进行递归
- 如果和不为10，那么在当前 `l` 加上1，结束