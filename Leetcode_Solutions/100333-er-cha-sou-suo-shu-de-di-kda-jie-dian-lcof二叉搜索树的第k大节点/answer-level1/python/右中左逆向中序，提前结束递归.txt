
class Solution(object):
    
    def kthLargest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.res = -1
        self.find = 0
        self.c = k  # 将k保存为递归之外的变量，防止回溯时k值不变而出错
        def dfs(root):
            if self.find: # 提前结束
                return
            if not root:
                return
            dfs(root.right)
            self.c -= 1
            if self.c == 0 and not self.find:
                self.res = root.val
                self.find = 1
            dfs(root.left)
            
            
        dfs(root)
        
        return self.res


