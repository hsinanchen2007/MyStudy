![TIM截图20200313113632.png](https://pic.leetcode-cn.com/df69b2b242cbbfebc51c003771dc08e2d36ef2c5346bcb611c86fb162dbc33d5-TIM%E6%88%AA%E5%9B%BE20200313113632.png)

### 解题思路
在上一题计算数深度的基础上，添加一个bool变量返回值，代表每个节点是否满足要求。发现其实就是个后续遍历。
另外，这题不加剪枝的话速度要打折，剪枝牛逼。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        #确实这个就是后序遍历，因为上一题求深度实际上也算后序遍历
        if root == None:
            return True
        _,res = self.depth(root)
        return res

    def depth(self,root):#一边测深度一边判断
        if root == None:
            return 0, True
        depth_l, bool_l = self.depth(root.left)#返回子树高度，以及子节点是否满足要求
        if not bool_l:return 0, False#剪枝，第一个返回值不重要
        depth_r, bool_r = self.depth(root.right)
        if not bool_r:return 0, False#剪枝，第一个返回值不重要
    
        now = False#标记当前节点是否满足
        if -1<=depth_l-depth_r<=1:
            now = True
        return 1+max(depth_l,depth_r), now#剪枝后 (now and bool_l and bool_r)#剪枝前

```
### 时间复杂度
应该是线性复杂度O(n)

### 个人见解，欢迎交流