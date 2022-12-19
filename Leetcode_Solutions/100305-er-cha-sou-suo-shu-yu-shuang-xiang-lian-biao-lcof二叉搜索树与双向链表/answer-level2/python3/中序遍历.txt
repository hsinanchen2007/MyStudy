```
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        stk = []
        if root == None: return  None
        stk.append(root)
        cur = root 
        head = pre = Node(-1)
        while stk:
            while cur.left :
                cur = cur.left
                stk.append(cur)
            cur = stk.pop()
            pre.right = cur 
            cur.left = pre 
            pre = cur
            while cur.right == None:
                if len(stk) == 0:
                    cur.right = head.right 
                    head.right.left = cur
                    return head.right 
                cur = stk.pop()
                pre.right = cur 
                cur.left = pre 
                pre = cur
            cur = cur.right 
            stk.append(cur)
```
