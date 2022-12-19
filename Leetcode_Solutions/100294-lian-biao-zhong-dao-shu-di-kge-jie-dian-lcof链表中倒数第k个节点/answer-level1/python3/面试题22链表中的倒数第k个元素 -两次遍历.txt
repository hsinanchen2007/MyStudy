### 解题思路
和876链表的中间节点相似，通过两次遍历解决
第一次遍历找到倒数第k个节点是正数第几个
第二次遍历终止于正数n-k+1节点

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        #和876链表的中间节点相似，可以通过2次遍历解决
        node=head
        count=1
        while node:
            count+=1
            node=node.next
        if count-k+1:#求出正序第几个
            firK=count-k+1
        else:return head
        i=1
        node=head
        while node and i<firK-1:
            i+=1
            node=node.next
        return node


```