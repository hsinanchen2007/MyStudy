思路就是把链表转换为列表，然后与之前的有序数组转换为二叉树思路一样
```
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if not head: return
        ls = []
        while head:
            ls.append(head.val)
            head = head.next
        def helper(lst):
            if not lst: return 
            mid = len(lst)//2
            root = TreeNode(lst[mid])
            root.left, root.right = helper(lst[:mid]), helper(lst[mid+1:])
            return root
        return helper(ls)
```