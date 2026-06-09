### 解题思路

### 递归法：
递归法对于解决数的问题十分常见，解本题的关键点在于把握上界和下界。
1.对于left子树的左节点来说需要确定好上界，对右节点来说需要确定好上界和下界
2.队友right子树的左节点来说需要确定好上界和下界，对右节点来说需要确定好下界。

因此通过递归的方式可以动态改变上下界限，其实递归中也用到了动态规划的一点思想，就是后面求得的值要依赖前面求得的值。
这里举个例子，比如右子树的左节点，它的依赖条件就不仅仅是它的上界限为它的父节点，还要满足它的下界限为它的父节点的下界限。

该条件写成代码也就是 `node.val（当前节点值） > min_（下界） and node.val < max_（上界）`

（这里说的可能有点绕，自己可以画一个图就明白了）

### 迭代法：
**思想：dfs或bfs，我的解法是dfs,当然将pop()（先进后出）换成pop(0)(先进先出),就变成了bfs。**
迭代法因为是正向的，所以理解起来没递归那么绕，但是会牺牲空间来换取时间，一般会创建队列或列表来进行迭代。
思路也是动态确定上界和下界
每次迭代从序列中pop()出节点和上界、下界，然后进行条件判断，满足条件即将左右子节点一次存入序列中，等待下次迭代。

最后的是二叉搜索树的结果应该序列为空，否则会中途return False


### 中序遍历：
我一开始想到了这种方法，但是遗憾的是我用了前序而不是中序，前序是用列表的insert()和append,但太想当然了，因为节点会在左和右中不断变化，无法有效确定节点添加的顺序。所以改用了递归和迭代。

后来，看了下官方解答，发现只要将前序换成中序遍历，中序的话append会以从小到大的顺序追加到列表。最后比较的条件就是
`result == sorted(result) and len(set(result)) == len(result)`
注：and前是判断是否是从小到大排序，and后是判断是否有相同的值出现，因为题目要求的是小于和大于，并不包括等于条件。
### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        # 递归法，动态缩减上下界范围，关键点是上下界的变化
        def compute_BST(root,max_ = float('inf'),min_ = float('-inf')):
            if not root:
                return True
            cur = root.val
            if cur >= max_ or cur <= min_:
                return False
            if not compute_BST(root.left,cur,min_):
                return False
            if not compute_BST(root.right,max_,cur):
                return False
            
            return True
        return compute_BST(root)
```
```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:     
        # 迭代算法，主要是创建一个可迭代的对象，例如列表，队列，先预存放一组数据，然后每次循环判断序列是否为空，不为空则继续判断条件，添加数据进去。直到队列为空。其实迭代算法也需要依赖前面的值求后面的值，就像max_和min_的动态变化
        if not root:
            return True
        result = [(root,float('inf'),float('-inf'))]
        while result:
            # 每次处理一个节点
            root,max_,min_ = result.pop()
            if not root :
                continue 
            val = root.val
            if val >= max_ or val <= min_:
                return False
            result.append((root.left,val,min_))
            result.append((root.right,max_,val))
        # 满足二叉搜索树的条件应该是result为空
        return True

```

```python
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:      
        #中序遍历，观察到中序遍历的顺序是左->中->右,也就是按照从小到大的顺序，因此这样思考题目就很好解了,按照中序遍历，将值依次存入列表中。最后判断
        if not root:
            return True
        result = []
        def middle_traversal(root):
            if root.left:
                middle_traversal(root.left)
            result.append(root.val)
            if root.right:
                middle_traversal(root.right)
        middle_traversal(root)
        return result == sorted(result) and len(set(result)) == len(result)
```