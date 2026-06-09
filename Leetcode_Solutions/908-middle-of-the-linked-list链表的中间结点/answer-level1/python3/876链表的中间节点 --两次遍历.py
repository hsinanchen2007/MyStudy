### 解题思路
可以进行两遍遍历：
第一遍记录有多少节点
第二遍找到中间节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if not head:return None#special cases
        if not head.next:return head
        #第一次遍历
        node=head
        count=0
        while node:
            count+=1
            node=node.next
        #第二次遍历
        mid=(count)//2
        i=0
        node=head
        while node and i<mid:
            i+=1
            node=node.next
        return node
            

```