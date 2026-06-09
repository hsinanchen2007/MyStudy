### 解题思路
定义一个子函数，能找到当前链表中间位置，能返回该中间位置的值，以及剩余的前半段链表和后半段链表
因为要把前半段链表截断，因此需要找中间位置的前驱

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedListToBST(self, head):
        """
        :type head: ListNode
        :rtype: TreeNode
        """
        ###迭代
        if not head:return head
        def fndCntNt(Head):
            if Head.next is None:return None,Head.val,None
            if Head.next.next is None: return None,Head.val,Head.next
            Fast=Head.next.next.next
            PerSlow=Head
            while Fast and Fast.next:
                PerSlow=PerSlow.next
                Fast=Fast.next.next
            PerSlow.next,Slow=None,PerSlow.next
            return Head,Slow.val,Slow.next
        def helper(head):
            Per,Val,Nxt=fndCntNt(head)
            Root=TreeNode(Val)
            if Per:Root.left=helper(Per)
            if Nxt:Root.right=helper(Nxt)
            return Root
        return helper(head)




            





```