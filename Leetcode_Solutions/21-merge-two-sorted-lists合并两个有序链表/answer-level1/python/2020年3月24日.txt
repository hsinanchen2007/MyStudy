### 解题思路
正常的归并方法
受到《python3 更简洁易懂高效的代码 + 更简单粗暴的解法》启发，在初始化链表的时候不用考虑第一个值，返回head.next即可
![image.png](https://pic.leetcode-cn.com/a0f157674f33e86517c72ba4deab19d7154b72cab0d5eef7a25dd272a562af0c-image.png)


此外，还有递归解法，待补充

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:          
        head = ListNode(0)
        l3 = head
        while l1 and l2:
            if l1.val > l2.val:
                l3.next = ListNode(l2.val)
                l2 = l2.next
            else:
                l3.next = ListNode(l1.val)
                l1 = l1.next
            l3 = l3.next
        l3.next = l1 or l2
        return head.next
        


```