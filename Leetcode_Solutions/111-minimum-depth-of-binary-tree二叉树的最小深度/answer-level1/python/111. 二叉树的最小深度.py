### 解题思路
**1，递归**
值得注意的一点是：只要左右子树至少存在一个，则说明该节点不是叶子节点，就需要继续往下寻找叶子节点，直到找到左右子树均为空的情况，而不能将null的一侧赋值为0。

### 代码

```python
class Solution(object):
    def minDepth(self, root):
        if not root:return 0
        #对于每一颗树而言，如果左右子树仅存在一边，那么就应顺着存在子树的方向寻找叶子节点，寻求最近值
        if not root.left:
            return 1 + self.minlen(root.right)
        if not root.right:
            return 1 + self.minlen(root.left)
        #若这棵树的两侧均存在子树，那么最近值就是以这两个子节点为根节点的树的节点最近值
        return 1 + min(self.minlen(root.left),self.minlen(root.right))

    def minlen(self,root1):
        if not root1:
            return 0
        #当左右子树为空时，该节点为叶子节点，返回个数1
        if not root1.left and not root1.right:
            return 1
        #若不是叶子节点，继续寻找
        return self.minDepth(root1)
        
        
```