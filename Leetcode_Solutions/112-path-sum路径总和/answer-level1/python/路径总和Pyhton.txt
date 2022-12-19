这一题怎么说呢，我感觉我也很难描述解法哈哈哈。它跟第110题特别类似，就是要准确理解叶子结点的概念。然后就是分情况讨论各种叶子结点对应路径的情况了，直接看代码吧！

代码如下：
```python
class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is None:
            return False
        if root.left is None and root.right is None:
            return sum == root.val
        elif root.left is not None and root.right is None:
            return self.hasPathSum(root.left, sum-root.val)
        elif root.left is None and root.right is not None:
            return self.hasPathSum(root.right, sum-root.val)
        else:
            return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)


# 创建二叉树
def build(data):
    if len(data) == 0:
        return TreeNode(0)
    nodeQueue = []
    # 创建一根节点，并将根节点进栈
    root = TreeNode(data[0])
    nodeQueue.append(root)
    # 记录当前行节点的数量
    lineNum = 2
    # 记录当前行中数字在数组中的位置
    startIndex = 1
    # 记录数组中剩余元素的数量
    restLength = len(data) - 1
    while restLength > 0:
        for index in range(startIndex, startIndex + lineNum, 2):
            if index == len(data):
                return root
            cur_node = nodeQueue.pop()
            if data[index] is not None:
                cur_node.left = TreeNode(data[index])
                nodeQueue.append(cur_node.left)
            if index + 1 == len(data):
                return root
            if data[index + 1] is not None:
                cur_node.right = TreeNode(data[index + 1])
                nodeQueue.append(cur_node.right)
        startIndex += lineNum
        restLength -= lineNum
        # 此处用来更新下一层树对应节点的最大值
        lineNum = len(nodeQueue) * 2
    return root


if __name__ == "__main__":
    nums = [1,-2,-3,1,3,-2,None,-1]
    root = build(nums)
    target = 3
    have_path = Solution().hasPathSum(root, target)
    print(have_path)
```
执行效率还算是不错的，在90%以上。

![image.png](https://pic.leetcode-cn.com/31d70689bdada64d5ea188dbd746835fff05bd0165ddfbd0d62a2c5b86c2a24e-image.png)
今天在做第113题路径总和II时，看到一些资料，突然想到这题还可以用更简单的方法来写。简而言之，就是我们可以不用讨论这么多种情况了，可以把它们给综合起来。

代码如下：
```python
class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if root is None:
            return False
        if root.left is None and root.right is None:
            return sum == root.val

        return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)
```
执行效率是和第一种方法一样，个人感觉会有所提升，也不懂为什么时间没有减少。

![image.png](https://pic.leetcode-cn.com/5f172b1229a5a49bff9a280b44d87a3db7b09275e8e6df4d2ea44c794d52b1a2-image.png)