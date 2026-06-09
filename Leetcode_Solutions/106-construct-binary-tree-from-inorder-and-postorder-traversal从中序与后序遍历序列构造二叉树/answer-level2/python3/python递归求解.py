```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder: return None
        root = TreeNode(postorder[-1])
        i = inorder.index(postorder[-1])
        root.left = self.buildTree(inorder[:i],postorder[:i])
        root.right = self.buildTree(inorder[i+1:],postorder[i:-1])
        return root
```
空间优化：参考了高赞题解
```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(inorder_l,inorder_r,postorder_l,postorder_r):
            if (inorder_l > inorder_r): return None
            i = inorder.index(postorder[postorder_r])
            root = TreeNode(postorder[postorder_r])
            root.left = helper(inorder_l,i-1,postorder_l,postorder_l-inorder_l+ i-1)
            root.right = helper(i+1,inorder_r,postorder_r-inorder_r+i,postorder_r-1)
            return root
        root = helper(0,len(inorder)-1,0,len(postorder)-1)
        return root
        # # 注意：第 4 个参数是计算出来的，依据：两边区间长度相等
        # root.left = self.__dfs(in_l, pos - 1, post_l, pos - 1 - in_l + post_l)
        # # 注意：第 3 个参数是计算出来的，依据：两边区间长度相等
        # root.right = self.__dfs(pos + 1, in_r, post_r - in_r + pos, post_r - 1)
        # return root
```
