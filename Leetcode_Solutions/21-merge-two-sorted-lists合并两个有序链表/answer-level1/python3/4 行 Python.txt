## 题解
```Python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if l1 and l2:
            if l1.val > l2.val: l1, l2 = l2, l1
            l1.next = self.mergeTwoLists(l1.next, l2)
        return l1 or l2
```
**备注：** 在 Python 中，and 和 or 都有提前截至运算的功能。
- and：如果 and 前面的表达式已经为 False，那么 and 之后的表达式将被 **跳过**，返回左表达式结果
- or：如果 or 前面的表达式已经为 True，那么 or 之后的表达式将被跳过，直接返回左表达式的结果
- 例子：`[] and 7` 等于 `[]`

**代码流程：**（按行数）
  - 判断 l1 或 l2 中是否有一个节点为空，如果存在，那么我们只需要把不为空的节点接到链表后面即可
  - 对 l1 和 l2 重新赋值，使得 l1 指向比较小的那个节点对象
  - 修改 l1 的 next 属性为递归函数返回值
  - 返回 l1，注意：如果 l1 和 l2 同时为 None，此时递归停止返回 None

**效率**
  - 时间复杂度：$O(n)$
  - 空间复杂度：【考虑递归开栈】$O(n)$【不考虑】$O(1)$

## 拓展
关于链表不熟的童鞋看过里 👻

![](https://pic.leetcode-cn.com/181bbe8bd0e65acd6a7415f9405e74f975dd1e1cd5c22df04a429d20b7aefe7c-QQ%E6%88%AA%E5%9B%BE20190606190157.png){:width="200"}
{:align="center"}

【🃏知识卡片】链表是数据结构之一，其中的数据呈线性排列。在链表中，数据的添加和删除都较为方便， 就是访问比较耗费时间。

**关键点：**
实际上，相比较数组来说，并不存在链表这样一个对象，链表是由多个节点组成的，因此，我们能接触到的数据对象只有节点。我们可以根据节点来寻找周围节点，许多节点之间的关系抽象地构成了一个链表。