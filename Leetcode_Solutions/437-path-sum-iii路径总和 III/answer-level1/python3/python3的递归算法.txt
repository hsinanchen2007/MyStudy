解题思路：题目要求计算出一棵树中所有自顶向下且和为sum的路径数量，简称路径数。
从组成上看：
 root包含路径数=以root为起点的路径数+左子树包含路径数+右子树包含路径数
其中左子树的路径数和右子树的路径数我们可以调用self.pathSum进行递归。
所以我们只需要计算以root为起点且和为sum的路径数，即：
以root为起点，且和为sum的路径的终点数量。有几个终点，就有几条路径。
递归方式如下：
```
def path(root,sum):                               #以root为起点且路径和为sum的终点数量
           if not root:
                return 0
           else:
                flag=1 if root.val==sum else 0    #若root本身就与sum相等，那其本身也算一个终点
                l=path(root.left,sum-root.val)    #左子树中包含的终点数量
                r=path(root.right,sum-root.val)   #右子树中包含的终点数量
                return flag+l+r                   #左子树节点+右子树节点+flag即为以root为起点且路径和为sum的终点数量

```

那么最终的函数在递归时调用path函数即可，代码如下：
```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        def path(root,sum):                         #以root为起点且路径和为sum的终点数量
           if not root:
                return 0
           else:
                flag=1 if root.val==sum else 0
                l=path(root.left,sum-root.val)
                r=path(root.right,sum-root.val)
                return flag+l+r
        if not root:
            return 0
        else:
            l=self.pathSum(root.left,sum)
            r=self.pathSum(root.right,sum)
            return l+r+path(root,sum)   #root包含路径数=以root为起点的路径数+左子树的路径数+右子树的路径数
```
