今天是刷code的第22天，虽然题很简单，但是是第一次一遍就通过，速度排名前1%，蛮开心的。
没有过多的技巧，就是递归。下面写一下思路，代码也有添加注释。
solution：
1 root.left != None, 那么count_left += 1,继续遍历过程maxDepth(root.left),右侧同理。
2 注意    同一层中的输出有两个，分别计数当前节点为根节点时，左子树的深度和右子树的深度，哪个深，比较一下就好啦，记得迭代同时把当前层的深度不要漏掉
3 注意X2  （怎么停止）左右子树均为空，那么返回计数深度 1
下为代码：
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        '''
        :type root:TreeNode
        :rtype: int
        '''
        # 上面未提及如果根节点直接为空， 无需遍历，返回0
        if root is None:
            return 0
        count1, count2 = 0, 0
        # 当前根节点的左子树是否为空
        if root.left != None:
            count1 += self.maxDepth(root.left) + 1
        # 当前根节点的右子树是否为空    
        if root.right != None:
            count2 += self.maxDepth(root.right) + 1
        # 当前节点为叶节点时，返回深度 1 
        if root.left == None and root.right == None:
            return 1
        return max(count1, count2)

```


