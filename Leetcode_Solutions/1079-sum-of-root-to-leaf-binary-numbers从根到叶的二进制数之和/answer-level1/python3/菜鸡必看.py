### 解题思路
不懂可以评论 一定回复
我也不懂位运算什么的 
就是一个10到2这样的转换吧

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        res=[]
        def helper(root,x) :
            if not root :
                return 
            if not root.left and not root.right :
                res.append(10*x+root.val)
            helper(root.left,10*x+root.val)
            helper(root.right,10*x+root.val)
        helper(root,0)
        sum=0
        for i in res :
            cur=int(str(i),2)
            sum+=cur
        return sum
        
```