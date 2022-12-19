### 解题思路
首先我们肯定要递归左右子树，想想我们要求什么？所有路径，很多条。
那我们递归应该返回什么？每次递归到底部就一条路径，所以直接递归返回所有条路径就行不通。
所以就有了参数tmp数组，记录一条可行的路径，然后满足条件我们就加一条路径到最后的结果，这样就能找到所有可行的路径了。
那终止条件是什么？
好理解一点就是直接看这个点要是叶子节点且到达这个点时我们的目标数被消除为0了。
那递归体里面为什么有left，right的判断？
因为我们这里的终止条件是not root.left and not root.right，注意这里不是not root。递归体里面传递的都是存在的节点，不可能是null
所以我们如果我们不判断not root.left and not root.right如果有个节点没有左节点或者没有右节点时，你再递归左右，null就进入递归了，就报错了。所以要保证每个进入递归的节点都不是null。
注意：为什么tmp第一次到底层输出了之后，为什么不是继续在tmp上添加一个一个的节点，因为每一层递归其实都新建了一个tmp，
即第一层是tmp1=[root.val],
第二层tmp2=tmp1+[root.left.val]....一直到第n层tmp(n)=tmp(n-1)+[root.left.val],他们各个tmp是不同的，
当到达第n层时，返回了，此时tmp就变到第n-1层的tmp了，所以后序添加是在第n-1层的tmp上添加的，不是在n层tmp上添加的，所以才保证了答案的正确性。
那什么时候要一直在原有的tmp上添加走呢，那就不应该把tmp当作参数传进来，而是把tmp定义为全局变量，以后遇到类似的题目需要注意。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root: return []
        res=[]
        def helper(root,ans,tmp):
            if not root.left and not root.right and ans==0:   #递归终止条件
                res.append(tmp)
                return
            if root.left:
                helper(root.left,ans-root.left.val,tmp+[root.left.val])
            if root.right:
                helper(root.right,ans-root.right.val,tmp+[root.right.val])
        helper(root,sum-root.val,[root.val])
        return res

```