### 解题思路
考虑用prev来存储最后生成的反转链表
遍历链表，将节点逐个加到prev上得到反转链表，所以整个过程是反向逐个节点生成prev，因此：
第一步：将prev初始为None
第二步：保存当前节点之后的节点，即：temp = curr.next
第三步：将当前节点的指针指向prev
第四步：将prev替换为当前节点，即完成将当前节点加到反转链表中
第五步：移动到下一个节点，即：curr = temp，跳转到第二步，直到遍历到最后一个节点


### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prev = None
        curr = head
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        return prev        
```