### 解题思路
统计子树和

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        self.d={}
        self.maxCnt=0
        def helper(root):
            if not root:
                return 0

            subSum=root.val+helper(root.left)+helper(root.right)
            self.d[subSum]=self.d.get(subSum, 0)+1
            self.maxCnt=max(self. maxCnt, self.d[subSum])
            return subSum
        helper(root)
        return [key for key, value in self.d.items() if value==self.maxCnt]
```