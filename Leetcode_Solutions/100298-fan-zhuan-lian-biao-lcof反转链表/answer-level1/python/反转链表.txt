### 解题思路
1、要注意判断边界条件，链表是否为空，链表是否只有1个数
2、整体的思路一定要清楚，总共要记3个变量，当前节点，前一个节点，下一个节点，每次只处理当前节点的next，其他节点的不要动。
来到当前节点，先记录当前节点的next；
如果当前节点为头结点，让当前节点的next为空；
如果当前节点是中间节点，让当前节点的next为last_node；
记录当前节点的last_node；
如果遍历到了最后一个节点，直接让这个节点的next为last_node。

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
        i = 0
        if head == None:
            return
        if head.next == None:
            return head
        last_node = ListNode(0)
        while head.next != None:
            next_node = head.next
            if i == 0:
                head.next = None
            else:
                head.next = last_node
            last_node = head
            # next_node.next = head
            # print(head.val)
            head = next_node
            i = i + 1
        head.next = last_node
        return head

```