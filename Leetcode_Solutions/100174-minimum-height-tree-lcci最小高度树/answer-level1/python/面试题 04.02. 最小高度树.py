### 解题思路
**方法一、递归**

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        def constuct_tree(left,right,num):
            if left > right:return None
            #若想高度最小，需要将中间元素作为根结点
            mid = (left + right)//2
            #构造新树
            ans = TreeNode(num[mid])
            #新树的左子树均由mid左侧元素构成
            ans.left = constuct_tree(left,mid-1,num)
            #新树的右子树均由mid右侧元素构成
            ans.right = constuct_tree(mid+1,right,num)
            return ans
        return constuct_tree(0,len(nums)-1,nums)
        
    
```
### 解题思路
原则上也是递归，但是没有构造新函数
```python
class Solution(object):
    def sortedArrayToBST(self, nums):
        if not nums:return None
        mid = len(nums)//2
        ans = TreeNode(nums[mid])
        ans.left = self.sortedArrayToBST(nums[:mid])
        ans.right = self.sortedArrayToBST(nums[mid+1:])
        return ans
        
    
```
