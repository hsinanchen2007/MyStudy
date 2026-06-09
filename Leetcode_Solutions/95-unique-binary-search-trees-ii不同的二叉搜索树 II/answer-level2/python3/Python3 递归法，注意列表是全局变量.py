### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        # 递归法
        # 把i = [1~n]作为根，左子树是[1~i-1]，右子树是[i+1, n]
        # 把所有情况加起来就是解

        if n == 0:
            return []
        
        ans = []
        def getAns(low, high):
            ans[:] = []
            if low > high:
                ans.append(None)
                return ans[:]
            if low == high:
                ans.append(TreeNode(low))
                return ans[:]
            
            res = []
            for i in range(low, high+1):
                left = getAns(low, i-1)
                right = getAns(i+1, high)
                for l in left:
                    for r in right:
                        node = TreeNode(i)
                        node.left = l
                        node.right = r
                        res.append(node)
            return res[:]

        return getAns(1, n)

```