### 1. 递归
总和等于左子树的值加上右子树的值，终止条件是当前节点为左子叶或者为空节点。代码如下：
```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        if not root:
            return 0
        if root and root.left and not root.left.left and not root.left.right:
            return root.left.val+self.sumOfLeftLeaves(root.right)
        return self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
```
#### 复杂度分析
时空复杂度均是O(n)

### 2. 迭代
采用迭代法先序遍历，判断当前节点的左子树是否为叶子节点。代码如下：
```
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        sum_ = 0
        if not root:
            return 0
        ans = [root]
        while ans:
            r = ans.pop()
            if r.left and not r.left.left and not r.left.right:
                sum_ += r.left.val
            if r.left:
                ans.append(r.left)
            if r.right:
                ans.append(r.right)
        return sum_
```
#### 复杂度分析
时空复杂度均是：O(n)，当实际上比上一题的时空复杂度表现要好。