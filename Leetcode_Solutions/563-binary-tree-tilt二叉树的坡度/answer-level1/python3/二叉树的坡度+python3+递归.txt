### 1. 递归
这题有两个定义：1. 总坡度；2. 节点坡度，需要辨别这两个定义的差别。递归的想法是定义一个辅助函数以及变量sum_(用于保存节点坡度)。代码如下：
```
class Solution:
    def __init__(self):
        self.sum_ = 0
    def findTilt(self, root: TreeNode) -> int:
        def find(root):
            if not root:
                return 0
            left = root.left.val + find(root.left) if root.left else 0
            right = root.right.val + find(root.right) if root.right else 0
            self.sum_ += (abs(left-right))
            return left+right
        find(root)
        return self.sum_
```
#### 复杂度分析：
__时间复杂度：__ O(n)

__空间复杂度：__  O(n)