### 解题思路
![image.png](https://pic.leetcode-cn.com/d6a8f3cbf7544020883dbf13185ea6783c7607ffebc1817f362f3f60da416073-image.png)
- 因为要找第`k`大的节点,我们又知道二叉搜索树的特征,根节点的值大于左子树小于右子树
- 由于需要找第`k`大,我们那就先遍历右子树,在遍历左子树,设置全局变量来统计第`k`个大的数即可
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthLargest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        K = [0]#用于计数
        result = [0]#用于保存结果
        def search_k(root, k):
            if not root:
                return
            search_k(root.right, k)
            K[0] += 1
            if K[0] == k:#当这个第K大的数时,返回
                result[0] = root.val
                return 
            search_k(root.left, k)
        search_k(root, k)
        return result[0]
            
            
```