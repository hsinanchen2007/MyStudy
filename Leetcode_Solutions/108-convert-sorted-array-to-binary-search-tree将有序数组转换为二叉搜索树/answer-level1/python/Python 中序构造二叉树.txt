### 解题思路
中序构造平衡二叉树
注意a = TreeNode(nums[l//2])赋值等于引向了一个新的节点
root =  TreeNode(nums[l//2])
ToBST(root.left,nums[0:l//2])
ToBST(root.right,nums[l//2+1:])
这种方法不行 每个root.left or root.right在下一个迭代里都跟之前的脱离关系了

### 代码

```python3
class Solution:
    def sortedArrayToBST(self, nums):
        def ToBST(nums):
            l = len(nums)
            if(l == 0):
                return None
            a = TreeNode(nums[l//2])
            a.left = ToBST(nums[0:l//2])
            a.right = ToBST(nums[l//2+1:])
            return a
        if(len(nums)==0):
            return None
        a = ToBST(nums)
        return a
```