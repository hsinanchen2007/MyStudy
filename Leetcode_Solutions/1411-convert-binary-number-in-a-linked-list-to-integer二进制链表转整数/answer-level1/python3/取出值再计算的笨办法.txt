### 解题思路
遇到跟链表调整值相关的题目把链表的值挨个取出来再单独操作不失为一种虽然很笨但是简单可行的操作，本题目也不例外：取出之后再计算十进制的值，如果是面试的话这样肯定不是最优解，因为对于大量的链表数据单独取值会占用很多额外的空间，不过先把基础的理解了再进阶吧，一步一步慢慢来(*￣︶￣)，PS：这个五千多的题号是什么鬼？

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getDecimalValue(self, head: ListNode) -> int:
        val, p = [], head
        while p:
            val.append(p.val)
            p = p.next
        return int(''.join(str(i) for i in val), 2)
```