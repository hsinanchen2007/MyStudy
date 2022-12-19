这一题的思路怎么说呢，也是很直接。就是遍历每一节点对应的左右子树的高度，判定其是否符合条件。只要发现其不符合，立即退出，判定其不是平衡二叉树；反之，若一直都符合条件，那我们可以说它就是平衡二叉树。

代码如下：
```python
class Solution(object):
    # 遍历每一节点的左右子树的高度，判定其是否符合条件；
    # 只要发现其不符合，立即退出，判定其不是平衡二叉树
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if root is None:
            return True
        # 分别定义左右子树的高度
        left_depth = 0
        right_depth = 0
        if root.left:
            left_depth = self.get_depth(root.left)
        if root.right:
            right_depth = self.get_depth(root.right)
        if abs(left_depth - right_depth) > 1:
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)

    # 获取某一节点对应树的最大高度
    def get_depth(self, root):
        if root is None:
            return 0
        else:
            return max(self.get_depth(root.left), self.get_depth(root.right))+1


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
    nums = [1,None,2,None,3]
    root = build(nums)
    is_balanced = Solution().isBalanced(root)
    print(is_balanced)
```
执行效率，还算是可以吧，在70%左右。

![image.png](https://pic.leetcode-cn.com/4600814752ccd7f9666b4347ce574ea029f86d0e1100661d3d1edab824ce6e30-image.png)