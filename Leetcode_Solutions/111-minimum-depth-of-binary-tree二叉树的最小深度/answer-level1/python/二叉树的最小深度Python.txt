这道题就是要深刻理解最小深度的意思了。我刚开始看这道题不假思索的写出了一种解法，方法如下：
```python
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        else:
            return min(self.minDepth(root.left), self.minDepth(root.right))+1


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
    nums = [3, 9, 20, None, None, 15, 7]
    root = build(nums)
    min_depth = Solution().minDepth(root)
    print(min_depth)
```
本来还洋洋得意，说这道题太easy，没成想迅速啪啪啪打脸。当时报错的测试用例是[1, 2]，如下图所示：

![image.png](https://pic.leetcode-cn.com/c94f8adb16fea147250f01a55bd95e68b20d625937e015a2afe3ab9bf5b7b7c6-image.png)
也就是说按照我的方法来，输出结果是1，但是正确答案是2。答案是没问题的，但我哪一步错了呢？错误之处就是我没有意识到：最小深度是从根节点到最近叶子节点的最短路径上的节点数量。在[1, 2]对应的树中，很明显，结点1不是叶子结点，结点2才是。但是按照我写的方法来说，就是默认了：只要当前节点的左右子树中出现了空节点，那么当前节点就是叶子结点。这个观点很明显是错的，所以在此基础上我又改进了，终于得出了正确结果。

代码如下：
```python
class Solution(object):
    # 这一题就是深刻理解最小深度的意思了
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if root is None:
            return 0
        # 如果当前非空节点的左子树为None，而右子树不为None，说明得在右子树中找叶子结点
        if root.left is None and root.right is not None:
            return self.minDepth(root.right)+1
        # 如果当前非空节点的左子树不为None，而右子树为None，说明得在左子树中找叶子结点
        elif root.left is not None and root.right is None:
            return self.minDepth(root.left)+1
        return min(self.minDepth(root.left), self.minDepth(root.right))+1
        

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
    nums = [1, 2, 3, None, 4]
    root = build(nums)
    min_depth = Solution().minDepth(root)
    print(min_depth)
```
执行效率还算不错，在90%以上。

![image.png](https://pic.leetcode-cn.com/fe25481240b4154f19e39c8c81ee4b9a5a0561c50dbf2c0e3f0a498ff16a3c68-image.png)