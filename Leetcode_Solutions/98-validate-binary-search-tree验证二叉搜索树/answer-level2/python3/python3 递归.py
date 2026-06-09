### 解题思路
对于一个节点：
1、找到左子树的所有值
2、找到右子树的所有值
3、分别和节点值比较，看是否符合条件，不符合就直接False，符合就继续
4、检查左右孩子是否满足


注意这个测试用例：
![image.png](https://pic.leetcode-cn.com/caee86ef82e3ec1996654916180256ba8a8adc38fdf75b95bb50c70ea42830df-image.png)
如果只关注每个节点和左右孩子，则5<10<15、6<15<20没有问题。
但6<10，6却在10的右子树里
因此遍历某一个节点时，需要和他左右子树（不只是左右孩子）的值进行比较
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def get_chrilren(root):
            if not root:
                return []
            if not root.left and not root.right:
                return [root.val]
            return [root.val]+get_chrilren(root.left)+get_chrilren(root.right)

        if not root:
            return True
        if not root.left and not root.right:
            return True
        # 拿到左右子树所有值
        left_children=get_chrilren(root.left)
        right_children=get_chrilren(root.right)
        #这里可以直接min找到最大值，然后比较的
        for i in left_children:
            if i>=root.val:
                return False
        for i in right_children:
            if i<=root.val:
                return False
        # 检查左右孩子的情况
        check_leftTree=self.isValidBST(root.left)
        check_rightTree=self.isValidBST(root.right)
        return check_leftTree and check_rightTree
```