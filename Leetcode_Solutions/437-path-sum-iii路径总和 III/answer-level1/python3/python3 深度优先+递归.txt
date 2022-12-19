### 解题思路
路径总和刷到第三题了，我们回顾一下前两题路径总和吧，或许对第三题会有启发作用。
路径总和1：**判断**该树中是否**存在**根节点到叶子节点的**路径**
路径总和2：找到所有从**根节点**到**叶子节点**路径总和等于给定目标和的**路径**
路径总和3：找出**路径和**等于给定数值的**路径总数**。路径**不需要**从根节点开始，**也不需要**在叶子节点结束，但是路径方向必须是**向下的**（只能从父节点到子节点）。

第一题：判断是否存在，我们使用递归，每次将target减去当前节点值得到新的target，将新的target传给子节点。一旦递归到叶子就判断target是否等零，有等零的就说明有，直接返回True
第二题：找到所有路径，在第一题的基础上提高了点难度，但做起来也还好，只要我们将过程中的路径临时保存起来，并在叶子节点而且target等零时将临时路径放到输出列表里就好了
第三题：看起来和第一题差不多，但与前两题完全不同的是——**路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的**，这就是说路径的开始和结尾不一定是根节点和叶子节点，要怎么做呢？

对于结尾，我们可以这么处理，在递归过程中发现target==0,就直接把计数count+1,然后继续往下递归
对于开头，我们可以将将每个节点作为开头进行尝试

代码如下：
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        if not root:
            return 0
        self.count=0
        def get_path(root,target):
            # 空节点直接返回
            if not root:
                return
            target-=root.val
            # 发现到达0，加1并继续遍历
            if target==0:
                self.count+=1
            # 到达叶子，返回
            if not root.left and not root.right:
                return
            get_path(root.left,target)
            get_path(root.right,target)
        # 广度有限遍历每一个节点
        stack=[root]
        while len(stack)>0:
            a=stack.pop(0)
            get_path(a,sum)
            if a.left:
                stack.append(a.left)
            if a.right:
                stack.append(a.right)
        return self.count
            
                
            
```