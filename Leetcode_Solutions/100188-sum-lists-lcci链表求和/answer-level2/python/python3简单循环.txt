### 解题思路
这个结果不知道算不算好
![image.png](https://pic.leetcode-cn.com/1e2d2a28753fe8e216aa76089405982d51414c56c5a58218fbfb02af3aab1637-image.png)

看到链表其实第一印象是用递归的, 后面想了一下还是直接写循环好了.
因为他本来第一位就是从个位开始的, 正好符合加法的运算规则, 所以直接每一位运算完就插入链表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        remaining = l1.val+l2.val
        head = ListNode(remaining%10)
        node = head
        remaining = remaining//10
        while l1.next or l2.next:
            l1 = l1.next or ListNode(0)
            l2 = l2.next or ListNode(0)
            remaining += l1.val+l2.val
            node.next = ListNode(remaining%10)
            node = node.next
            remaining = remaining//10
        if remaining:
            node.next = ListNode(remaining)
        return head




```