### 解题思路
做了40分钟，终于过了！！！！！
![f514d368272633f29564f60a82d6bead66f16127cfe9dbcf7ee234ff56bf08c3-image.png](https://pic.leetcode-cn.com/36be5eb1d74e51c66a1e15095ebcd98bd88202a2cbb5157737fc0be70eab3307-f514d368272633f29564f60a82d6bead66f16127cfe9dbcf7ee234ff56bf08c3-image.png)

这题和这题很像：[543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/),都是求最大路径，且路径不一定过根节点的，但543这题比较简单，对于路径上的节点值没有限制。类似的，我们看看543这题能给我们带来什么启发：
```
class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        def track(root):
            if not root:
                return 0
            left = track(root.left)
            right = track(root.right)
            # 核心是返回值和存储值不一样
            # 存储的是当前的最长路径
            # 返回的是可以给根节点提供什么
            re.append(left+right+1)
            return max(left, right) + 1
        re = []
        track(root)
        return max(re)-1
```
在这题中，结合下面这个例子：
![image.png](https://pic.leetcode-cn.com/8f878e7b700ce2f906117bb78203931e116dfd5aae061c5d55db43c7c90b048f-image.png)
当我们遍历到Left1的时候，得到了一条路径包含4个节点（左边两个1，右边一个1，自身一个1.一共四个节点，长度是3）,我们将他存储起来。在向调用者Root1返回时，我们返回3，也就是左边两个1加自身组成的路径的节点数，**表明Root1如果想从这边走，Left1可以提供节点数为2的路径**。

加粗的地方是这道题的核心，也就是返回值的意义，**当我们做递归时，最重要的一点就是理清返回值的含义**！这道题中，返回值代表自身的根节点如果想从这边走，本节点可以提供多少节点的路径。

核心点解决了，还有一些递归的边角料需要解决：
* 如何处理空节点和叶子节点？
空节点返回0，叶子返回1，他们可以给父节点提供0,1个节点的路径

* 拿到左右孩子的返回值后，需要做什么处理？
以左孩子为例，拿到后，先判断左孩子和自己一不一样，一样的话说明自己可以从左孩子这边走，返回值加一，不一样就返回值重置为0。
* 对于左右孩子都不可以走，左右孩子只有一个可以走，左右孩子都可以走，该怎么操作？
     * 左右孩子都不可以走，说明本节点和左右都不一样，存储1，直接返回1
    * 左右孩子只有一个可以走，此时因为路径长度=节点数-1，需要-1后存储，返回左右孩子中最大的+1
    * 左右孩子都可以走，此时因为本节点被重复计算了，需要再减去1，存储-2后的值，返回左右孩子中最大的+1

详细见代码：

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 0
        re=[]
        def get_length(root):
            if not root:
                return 0
            if not root.left and not root.right:
                return 1
            left=0
            right=0
            if root.left:
                left=get_length(root.left)
                if root.left.val==root.val:
                    left+=1
                else:
                    left=0
            if root.right:
                right=get_length(root.right)
                if root.right.val==root.val:
                    right+=1
                else:
                    right=0
            if left==0 and right==0:
                re.append(0)
            if left>0 and right>0:
                re.append(left+right-2)
            else:
                re.append(left+right-1)
            return max(left,right,1)
        get_length(root)
        print(re)
        return max(re)

```