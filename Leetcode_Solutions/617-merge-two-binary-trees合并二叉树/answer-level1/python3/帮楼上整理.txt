作者：xiaolongsoft
链接：https://leetcode-cn.com/problems/two-sum/solution/he-bing-si-lu-by-xiaolongsoft/

```python []
def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode: 
        if t1 is None:
                t1 = t2 
        elif t2 is not None:
                t1.val = t1.val + t2.val
        t1.left = self.mergeTrees(t1.left, t2.left)
        t1.right = self.mergeTrees(t1.right, t2.right) 
        return t1
```