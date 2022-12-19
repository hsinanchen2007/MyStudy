### 解题思路

其实思路很简单，完全二叉树有以下两种情况：
1、如果为满二叉树，则可以直接根据公式 n = 2^h-1 返回；
2、如果不是满二叉树，则分别递归地求左子树节点数量、右子树节点数量，最后加上本身节点数量 1 并返回。

判断完全二叉树是否为满二叉树直接看最左和最右两个节点高度是否一致即可。

### 时间复杂度分析

值得注意，**第2种情况下，左、右子树至少有一棵是满二叉树**，画出完全二叉树来你就知道啦~
故实际上只有至多一棵子树（即非满完全二叉树）会往下继续递归求解，而另那一棵子树（即满二叉树）直接返回结果。
因此每一层只有一个节点会进行递归求解，即至多需要判断 h 次是否为满二叉树，而每次判断完全二叉树是否为满二叉树的时间复杂度为 O(h)。
故总的时间复杂度为 O(h^2)。


### 代码

```
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        is_full, h = self.is_full(root)   # 判断是否为满二叉树，顺便返回高度
        if is_full:            # 如果为满二叉树直接根据公式返回结果
            return 2 ** h - 1

        return 1 + self.countNodes(root.left) + self.countNodes(root.right)  # 至少其中一棵子树是满二叉树，会直接返回结果

    # 判断是否为满二叉树，返回元组 (是否为满二叉树, 树最右端节点的高度)
    def is_full(self, root): 
        right_height = 0
        p1 = root
        p2 = root
        while p2:
            p1 = p1.left       # 找最左端节点
            p2 = p2.right      # 找最右端节点 
            right_height += 1
        if p1:                 # p2 比 p1 先为空，说明不是满二叉树
            return (False, right_height) 
        else:                  # p1, p2 同时为空，为满二叉树
            return (True, right_height)
```