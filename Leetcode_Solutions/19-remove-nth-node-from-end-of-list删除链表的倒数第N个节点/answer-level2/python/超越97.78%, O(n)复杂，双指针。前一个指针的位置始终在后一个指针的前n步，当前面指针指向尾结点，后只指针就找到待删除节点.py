### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    """
    双指针：
    前指针：front， 从0+n开始
    后指针：behind， 从0开始
    当front到达尾结点，behind刚好到达待删除节点的前一个节点
    时间复杂度O(n)
    """
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        #初始化两指针
        behind = front = head
        while n > 0:
            front = front.next
            n -= 1
        #假入front此时就在最后一个，那front==None,没有next
        if front != None:
            while front.next != None:
                behind = behind.next
                front = front.next
            behind.next = behind.next.next
        #front到达最后一个说明要删除第一个元素
        else:
            head = head.next
        return head
```