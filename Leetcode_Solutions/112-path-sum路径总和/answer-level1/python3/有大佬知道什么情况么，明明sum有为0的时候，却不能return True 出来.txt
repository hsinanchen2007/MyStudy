
```
```python []
# class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if root == None:
            return False
        sum=sum-root.val
        print(sum)
        if  sum ==0:
            return True
        for i in range(2):
            if i==0:
                if root.left:
                    self.hasPathSum((root.left),sum)
            if i ==1:
                if root.right:
                    self.hasPathSum((root.right),sum)
        return False

```

