### 解题思路
有序链表找中间节点使用快慢指针，fast指针比slow指针多走一步，fast指针走到尾时，slow指针刚好指向近似中间节点。找到中间节点就可以利用类似于【有序数组转换二叉搜索树】的方法来进行递归了。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:     
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        return self.helper(head, None)

    def findmid(self, head, tail):
        slow = head
        fast = head
        while fast != tail and fast.next != tail:
            slow = slow.next
            fast = fast.next.next
        return slow

    def helper(self, head, tail):
        if head == tail:
            return
        node = self.findmid(head, tail)
        root = TreeNode(node.val)
        root.left = self.helper(head, node)
        root.right = self.helper(node.next, tail)
        return root


    
    
        

    
        
```