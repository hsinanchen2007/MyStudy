### 解题思路
这个思路是按照别人的题解做的，非原创.
核心想法在在BST的构建。
1 中序遍历获取到排序好的结果
2 将排好序的数组通过二分的方案进行切分，中间的点是根结点，左边是左子树，右边是右子树，然后递归将左子树切分，右子树切分。
done

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 中序遍历
    def mid_sort(self, root, res):
        if root:
            if root.left:
                self.mid_sort(root.left, res)
            res.append(root)
            if root.right:
                self.mid_sort(root.right, res)
    # 创建BST
    def createBST(self, res, l_idx, r_idx):    
        mid = (l_idx + r_idx) // 2
        mid_point = res[mid]
        mid_point.left = None
        mid_point.right = None
        if l_idx < mid:
            mid_point.left = self.createBST(res, l_idx, mid-1)
        if r_idx > mid:
            mid_point.right = self.createBST(res, mid+1, r_idx)
        return mid_point
        
        
    def balanceBST(self, root: TreeNode) -> TreeNode:
        if root == None:
            return None
        res = []
        self.mid_sort(root, res)
        return self.createBST(res, 0, len(res)-1)
    
        
```