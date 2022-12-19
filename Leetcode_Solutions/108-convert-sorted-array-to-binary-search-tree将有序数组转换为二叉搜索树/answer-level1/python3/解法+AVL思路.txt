没有用到AVL的知识的代码：
```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode: 
        # print("传入的nums:",nums)
        if len(nums)==1:
            return TreeNode(nums[0])
        elif len(nums)==0:
            return None
        mid=len(nums)//2
        midvalue=nums[mid]
        root=TreeNode(midvalue)
        root.left=self.sortedArrayToBST(nums[:mid])
        root.right=self.sortedArrayToBST(nums[mid+1:])
        return root
```
此题是关于建立平衡二叉排序树的一个问题，但是由于问题的对象是一个升序或者降序的nums，可以通过取中值来得到一种解法，但是如果输入的nums是一个任意的列表，我们该如何建立一颗AVL？
