```

#二叉树的公共祖先问题
class Solution:
    def BST_lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #二叉搜索树的公共祖先问题，利用好二叉树的性质：p q 的值一个大于一个小于root，直接返回root   否则肯定位于root的左边 或右边
        while root:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root
    
    # 
    # 如果当前root值等于p q中的一个，直接返回root
    # 后边算法主要基于后续遍历：
    # 三种情况，p q 各在root的左右子树 返回 root
    #   p q全在root右子树 返回找到的右子树节点  全在左 返回左子树节点
    def Postorder_lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None
        if root.val==p.val or root.val == q.val:
            return root
    
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        if left:
            return left
        if right:
            return right
        return None

    # 主要基于先序遍历，用数组记录两条路径，找到两个路径值：
    # 
    def Pretorder_lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None
        
        path1,path2 = [],[]
        def dfs(root,value,path):
            # root 为空，返回false
            # 1）存储节点 push(root)
            #   2）如果节点值等于value，返回True （不pop root）
            #   3）如果value在root 的左子树或者右子树，返回True (不pop root)
            # 4）pop root
            if not root: return False
            path.append(root)
            if root.val == value:
                return True
            if dfs(root.left,value,path) or dfs(root.right,value,path):
                return True
            path.pop()

        dfs(root,p.val,path1)
        dfs(root,q.val,path2)
        # print(path1,path2)
        for i in range(len(path1)-1,-1,-1):
            for j in range(len(path2)-1,-1,-1):
                if path1[i].val == path2[j].val:
                    return path1[i]

        # return None  ```

#二叉树的公共祖先问题
class Solution:
    def BST_lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        #二叉搜索树的公共祖先问题，利用好二叉树的性质：p q 的值一个大于一个小于root，直接返回root   否则肯定位于root的左边 或右边
        while root:
            if p.val < root.val and q.val < root.val:
                root = root.left
            elif p.val > root.val and q.val > root.val:
                root = root.right
            else:
                return root
    
    # 
    # 如果当前root值等于p q中的一个，直接返回root
    # 后边算法主要基于后续遍历：
    # 三种情况，p q 各在root的左右子树 返回 root
    #   p q全在root右子树 返回找到的右子树节点  全在左 返回左子树节点
    def Postorder_lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None
        if root.val==p.val or root.val == q.val:
            return root
    
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            return root
        if left:
            return left
        if right:
            return right
        return None

    # 主要基于先序遍历，用数组记录两条路径，找到两个路径值：
    # 
    def Pretorder_lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if not root: return None
        
        path1,path2 = [],[]
        def dfs(root,value,path):
            # root 为空，返回false
            # 1）存储节点 push(root)
            #   2）如果节点值等于value，返回True （不pop root）
            #   3）如果value在root 的左子树或者右子树，返回True (不pop root)
            # 4）pop root
            if not root: return False
            path.append(root)
            if root.val == value:
                return True
            if dfs(root.left,value,path) or dfs(root.right,value,path):
                return True
            path.pop()

        dfs(root,p.val,path1)
        dfs(root,q.val,path2)
        # print(path1,path2)
        for i in range(len(path1)-1,-1,-1):
            for j in range(len(path2)-1,-1,-1):
                if path1[i].val == path2[j].val:
                    return path1[i]

        # return None  
```

```
