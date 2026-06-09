非递归的，后序既然是左-右-中，倒序就是中-右-左，把前序的左右互换就好了，只是输出时序列反转一下。
```
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        #not recur
        res=[]
        cur,stack=None,[root]
        while cur or stack:
            if cur:
                res.append(cur.val)
                if cur.left:
                    stack.append(cur.left)
                cur=cur.right
            else:
                cur=stack.pop()
        return res[::-1]
```
