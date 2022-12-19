```
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if head == None:
            return None
        stack=[]
        while head:
            stack.append(head.val)
            head=head.next
########变成list
        def helper(stack):
            if stack == []:
                return None
            size=len(stack)
            mid = size//2
            ans=TreeNode(stack[mid])
            ans.left = helper(stack[0:mid])
            ans.right = helper(stack[mid+1:])
            return ans
        return helper(stack)
```
