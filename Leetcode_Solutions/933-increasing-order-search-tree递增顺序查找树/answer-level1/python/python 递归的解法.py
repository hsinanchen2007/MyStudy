### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def helper(self, root):
        if root is None:
            return (None, None) # head 
        else:
            headLeft, tailLeft = self.helper(root.left)
            headRight, tailRight = self.helper(root.right)
            thisHead = None
            thisTail = None
            root.left = None
            root.right = None


            if headLeft is None:
                thisHead = root
            else:
                thisHead = headLeft
                tailLeft.right = root
            
            if headRight is None:
                thisTail = root
                root.right = None
            else:
                root.right = headRight
                thisTail = tailRight
            return (thisHead, thisTail)

    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        return self.helper(root)[0]
```