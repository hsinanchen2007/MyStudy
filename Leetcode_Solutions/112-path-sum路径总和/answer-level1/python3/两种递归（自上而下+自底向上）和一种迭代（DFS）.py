### 递归--自上而下
题目是自上而下的经典应用了，预设结果值`self.rst`为False，将节点前面的累计和作为参数，逐个向下传递。当到达叶子节点，修改结果值为`self.rst |= (_sum+node.val==sum)`。若不是叶子节点，继续向下访问。
```python
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        # # 自顶向下
        self.rst=False
        def path_sum(node,_sum):
            if node==None:
                return
            elif node.left==node.right==None:
                self.rst |= (_sum+node.val==sum)
                return  
            else:
                path_sum(node.left,_sum+node.val)
                path_sum(node.right,_sum+node.val)
        path_sum(root,0)
        return self.rst
# 执行用时 :36 ms, 在所有 python3 提交中击败了99.62%的用户
# 内存消耗 :14.4 MB, 在所有 python3 提交中击败了99.28%的用户
```
### 递归--自下而上
有了自上而下的递归，很容易写出自下而上的递归：
```python
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        # # 自底向上
        def path_sum(node,_sum):
            if node is None:
                return False 
            elif node.left==node.right==None:
                return node.val+_sum == sum
            else:
                return path_sum(node.left,node.val+_sum)| path_sum(node.right,node.val+_sum)
        return path_sum(root,0)
```
### 迭代--深度优先搜索
题目要求判断到达叶子节点时是否总和等于目标，这显然是DFS的应用了。
如[python3最基础的BFS套路代码，适合入门新手！](https://leetcode-cn.com/problems/perfect-squares/solution/python3zui-ji-chu-de-bfstao-lu-dai-ma-gua-he-ru-me/)所述，类比一下DFS算法组成的三元素：栈，入栈出栈的节点，已访问集合。
- 栈的先入先出可以保证深度优先。
- 节点要写成（node,_sum)保证每一步有逐步更新的记录。
- 已访问集合可以忽略，二叉树没有重复节点。

每弹出一个节点，若为叶子节点且累计和等于目标，返回True，否则更新累计和。然后对弹出节点的非None子节点入栈。
```python
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        # # DFS
        stack =root and [(root,0)]
        while stack:
            i,_sum = stack.pop()
            if i.left==i.right==None and i.val+_sum==sum:
                return True
            else:
                _sum +=i.val
            [stack.append((x,_sum)) for x in [i.left,i.right] if x]
        return False
# 执行用时 :44 ms, 在所有 python3 提交中击败了95.62%的用户
# 内存消耗 :14.2 MB, 在所有 python3 提交中击败了99.46%的用户
```