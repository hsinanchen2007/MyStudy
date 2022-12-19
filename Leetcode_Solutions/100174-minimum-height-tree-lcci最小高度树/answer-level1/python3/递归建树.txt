### 解题思路
本次使用的递归思想是非常基础且重要的。思路就是首先从数组的中间位置建立跟节点，然后元素左边的递归建立左子树，元素右边递归建立右子树。

### 代码

```python []
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        left, right = 0, len(nums) - 1
        if left > right:
            return None

        mid = (left + right) // 2
        root = TreeNode(nums[mid]) # 跟节点
        root.left = self.sortedArrayToBST(nums[:mid]) # 建立左子树
        root.right = self.sortedArrayToBST(nums[mid + 1:]) # 建立右子树
        return root
```
### 复杂度分析
- 时间复杂度：$O(n)$，递归涉及到每一个元素。
- 空间复杂度：$O(n)$。