```

        # self.index = 0
        # self.mark = 0
        # def find(root):
        #     if self.mark == 1: return 
        #     if root == None: return 
        #     find(root.right)
        #     self.index += 1
        #     if self.index == k: 
        #         self.mark = 1
        #         self.ans = root.val
        #         return 
        #     find(root.left)
        # find(root)
        # return self.ans
```

```
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:

        stk = []
        if root == None: return  stk
        stk.append(root)
        cur = root 
        ans = -1
        index = 0
        while stk:
            while cur.right :
                cur = cur.right
                stk.append(cur)
            cur = stk.pop()
            index += 1
            if index == k: return cur.val
            while cur.left == None:
                if len(stk) == 0: return  ans
                cur = stk.pop()
                index += 1
                if index == k: return cur.val
               
            cur = cur.left 
            stk.append(cur)
        return   ans 
```
