### 解题思路
求子树树高，从底向上更新每个访问节点高度。
### 自底向上1
```python3
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def ib(node):
            if node==None:return 0,True                
            l_depth,l_flag = ib(node.left)
            r_depth,r_flag = ib(node.right)
            n_depth,n_flag = max(l_depth,r_depth)+1, abs(l_depth-r_depth)<2
            return n_depth,n_flag&l_flag&r_flag
        return ib(root)[1]
```
上面方法中规中矩，只是发现不平衡时不能及时返回答案，要到根节点才行。改进如下：
### 自底向上2
```python3
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        def ib(node):
            if node==None:return 0                
            l_depth = ib(node.left)
            r_depth = ib(node.right)
            assert abs(l_depth-r_depth)<=1
            return max(l_depth,r_depth)+1
        try:ib(root)
        except:return False
        else:return True
```
当符合条件，直接断言报错退出程序。
我还试了下自顶向下的方法。
### 自顶向下1
按照之前求树高的代码，自顶向下求每个子节点的树高。此方法要每个节点从底开始算一次，时间复杂度n²了，于是我想到下面一种方法。
### 自顶向下2
root节点深度设为1，每向下访问一个节点，该节点深度更新为2，依次类推，这完美符合自顶向下的递归思路
```python3
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.depth = None

class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        if root:root.depth=1
        self.rst = set() if root else set([0])
        def ib(node):
            if node==None:
                return
            if None in [node.left,node.right]:                
                self.rst.add(node.depth)
            if node.left:
                node.left.depth = 1+node.depth
            if node.right:
                node.right.depth = 1+node.depth
            ib(node.left)
            ib(node.right)       
        ib(root)
        return max(self.rst)-min(self.rst)<=1
```
可是！其他很完美，但在[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5] 这个测试例子中解答错误！原来这样算是求的树深度，树深度和高度是有点不同的！两者之间的转化还挺复杂，没想出好办法来。就这样记录一下吧，看来不是所有递归题目都可以2种方法通用的。
