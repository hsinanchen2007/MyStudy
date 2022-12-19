### 解题思路
1、每次取中位数作为root；
2、基数和偶数无所谓；
3、终止条件为nums没有数据了，则是叶子结点，则return None

### 代码

```python3
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        if len(nums) == 0:
            return None

        mid = len(nums) // 2

        root = TreeNode(nums[mid])
        root.left = self.sortedArrayToBST(nums[:mid])
        root.right = self.sortedArrayToBST(nums[mid + 1:])
        return root

```