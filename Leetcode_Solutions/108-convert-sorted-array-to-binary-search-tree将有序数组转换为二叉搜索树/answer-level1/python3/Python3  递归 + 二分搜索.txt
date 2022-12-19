思路: 借鉴二分搜索, 递归很好理解,很容易实现
```
    def sortedArrayToBST(self, nums: list) -> TreeNode:
        if nums is None:
            return None
        begin = 0
        end = len(nums) - 1
        return self.buildTree(nums, begin, end)
    
    def buildTree(self, nums: list,  begin: int, end: int):
        if begin > end:
            return None
        mid = (begin + end) >> 1
        root = TreeNode(nums[mid])
        
        root.left = self.buildTree(nums, begin, mid - 1)
        root.right = self.buildTree(nums, mid + 1, end)
        return root
```

#### 复杂度分析
时间复杂度: O(n)
空间复杂度: O(n)
(ps: 如有错误,欢迎大神批评与指正)