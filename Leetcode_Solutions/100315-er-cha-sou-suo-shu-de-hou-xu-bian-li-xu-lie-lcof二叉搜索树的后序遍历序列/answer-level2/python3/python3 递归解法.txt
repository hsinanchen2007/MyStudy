```
class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        #  空树也属于二叉搜索树
        if not postorder or len(postorder)==1:
            return True
        n = len(postorder)
        # 后序遍历，根的值在最后
        root = postorder[-1]
        # 二叉搜索树左子树上所有值 < 根植 < 右子树上所有值
        # 确定左子树与右子树的分界点
        part = n-1
        for i in range(n):
            if postorder[i]>root:
                part = i
                break
        left = postorder[:part]
        right = postorder[part:n-1]
        # 检查左右子树是否有不符合要求的节点
        for num in left:
            if num>root:
                return False
        for num in right:
            if num<root:
                return False
        # 检查左、右子树是否分别是二叉搜索树
        lret = self.verifyPostorder(left)
        rret = self.verifyPostorder(right)
        return lret and rret
        

```
