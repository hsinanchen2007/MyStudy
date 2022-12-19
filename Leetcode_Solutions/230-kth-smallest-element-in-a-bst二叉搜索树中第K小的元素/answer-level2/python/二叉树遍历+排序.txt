思路：遍历二叉树，得到全部元素list，然后排序，按给定k值查找。
```
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        nums = []
        # 二叉树前序遍历函数
        def positive_order_traver(root):
            if root is None:
                return 
            nums.append(root.val)
            positive_order_traver(root.left)
            positive_order_traver(root.right)
        positive_order_traver(root)
        # 排序
        nums.sort()
        # 按指定索引查找        
        return nums[k-1]
```
