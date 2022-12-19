### 解题思路
将题目拆解为：中序遍历+有序数组求众数，2个简单的小问题。虽然这样时间复杂性较高，但是程序比较好理解

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return []
        ans=[]#存储结果
        nums=[]#数组，用于存储中序遍历的数组
        max_num,cur_num=1,1
        def inorderTraversal(node):#中序遍历
            if not node:
                return 
            inorderTraversal(node.left)
            nums.append(node.val)
            inorderTraversal(node.right)
        inorderTraversal(root)
        ans.append(nums[0])#初始化数组
        for i in range(1,len(nums)):#有序数组求众数，比较当前与前一个的关系，注意范围
            if nums[i]==nums[i-1]:
                cur_num=cur_num+1
            else:
                cur_num=1
            if cur_num==max_num:
                ans.append(nums[i])
            elif cur_num>max_num:
                ans=[]
                ans.append(nums[i])
                max_num=cur_num
        return ans
```