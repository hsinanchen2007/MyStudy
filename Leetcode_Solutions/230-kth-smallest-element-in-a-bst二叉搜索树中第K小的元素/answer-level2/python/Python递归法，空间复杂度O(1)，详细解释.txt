### 解题思路
- 二叉搜索树的特点在于，任何一个结点的“左边”是比该节点小的值，“右边”是比该节点大的值，因此如果某个节点知道自己左边有k-1个节点，那自己就刚好是第k大节点了。
- 考虑如何让某个节点知道自己“左边”有多少个节点
 - 一个节点“左边”的节点数有两个来源，一是自己的左子树的节点数（递归左子树得到的返回值即是左子树总节点个数）
 - 另一个来源需要仔细理解一下：父节点的“左边”的节点数也一定在自己的“左边”；如果自己是父节点的右子树，那还要再+1，因为父节点也在左边
 - 由于递归中某个节点不能知道自己的父节点是谁，所以每个父节点要在参数中主动告诉子节点：“我的左边有多少节点”
- 递归函数的返回值用来数“本节点所在的子树一共有多少个节点”
### 代码

```python
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.ans=0
        def dfs(root,leftn):                #leftn表示在本root节点的父节点的“左边”一共有多少个元素
            if root==None:return 0
            l=dfs(root.left,leftn)
            if l==-1:return -1              #返回-1是为了在找到结果之后把后面的枝全部剪掉
            if leftn+l==k-1:                   
                self.ans=root.val
                return -1
            r=dfs(root.right,leftn+l+1)
            if r==-1:return -1
            return l+r+1
        dfs(root,0)
        return self.ans
```