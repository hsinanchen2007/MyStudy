### 自底向上
自底向上的递归，总体思路是：当前节点的数值可以从其子数值算出。
所以只需要知道叶子节点的深度，向上更新，就知道了根节点深度。
显然这是一种后序遍历（左→右→根）。基础代码如下：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:        
        # 自底向上
        def func(node):
            if node==None: ## 若节点为None
                return 0
            elif node!=None and node.left==node.right==None: ## 若节点为叶子节点
                return 1
            elif node!=None and ~(node.left==node.right==None): ##若节点为非叶子节点
                return max(func(node.left),func(node.right))+1 ## 当前节点深度是其子节点深度最大值+1
        return func(root)
# 执行用时 :68 ms, 在所有 python3 提交中击败了15.32%的用户
# 内存消耗 :14.8 MB, 在所有 python3 提交中击败了86.36%的用户
```
这样的思路很直观，也可以写的更pythonic一点：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:        
        # 自底向上
        p = lambda x: max(p(x.left),p(x.right))+1 if x else 0
        return p(root)
```
### 自顶向下
自顶向下的递归，总体思路是：最终结果可以由根节点到叶子节点一步步累计得出。
所以先预设结果数值，从根节点向下，每向下一次就更新一次结果数值，直到下降到叶子节点，就得到了这条线的深度。各条线的深度取最大值，就是根节点最大深度。
显然这是一种前序遍历（根→左→右），基础代码如下：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int: 
        # 自顶向下
        self.rst = 1 if root else 0 ## 预设结果值
        def func(node,length):
            if node==None: ## 若节点为None
                return
            elif node!=None and node.left==node.right==None: ## 若节点为叶子节点
                self.rst = max(self.rst,length) ## 取较大的深度为结果值并停止递归
                return
            elif node!=None and ~(node.left==node.right==None): ##若节点为非叶子节点
                length = length+1 ## 当前线路深度+1
                func(node.left,length) ## 传递深度值参数，向下继续访问
                func(node.right,length) ## 传递深度值参数，向下继续访问
        func(root,self.rst)
        return self.rst
```
这个思路比较抽象，如leetcode教程所述，当遇到树问题时，请先思考一下两个问题：
1. 你能确定一些参数，从该节点自身解决出发寻找答案吗？
    `---访问节点可以更新参数，树中完成访问的各条线的最终参数，经某种确定的函数运算（本例是求最大值）后就是结果值`
2. 你可以使用这些参数和节点本身的值来决定什么应该是传递给它子节点的参数吗？
    `---传入子节点的参数=本节点的参数（length）+节点本身的值（本例中是单个节点深度1）`

这样的思维方式熟悉一下，可以写的更简洁：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int: 
        # 自顶向下
        self.rst = 0
        def func(node,length):
            if node == None:
                self.rst = max(length,self.rst)
                return
            elif node != None:
                func(node.left,length+1)
                func(node.right,length+1)
        func(root,self.rst)
        return self.rst
# 执行用时 :40 ms, 在所有 python3 提交中击败了98.19%的用户
# 内存消耗 :14.9 MB, 在所有 python3 提交中击败了86.22%的用户
```
