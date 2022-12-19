**解题思路：**二叉搜索树的中序遍历是升序排序的结果，所以只需要返回中序遍历结果的第k个结点的值。

## 示例代码1:
**建立中序遍历的列表，查找第k-1个结果：**
    
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        #存放排好序的树节点的值
        res = []
        #递归搜索左右子树的函数
        def SearchTree(res, root):
            if root == None:
                return 
            ltree = SearchTree(res, root.left)
            #中序遍历是已经排好序的
            res.append(root.val)
            rtree = SearchTree(res, root.right) 
        SearchTree(res, root)
        return res[k-1]


## 示例代码2：
**继续优化空间复杂度，用num记录访问次数，当num等于k时返回访问结果：**

    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        #用于记录已经访问的结点数量
        global num
        num = 0
        #递归访问左右子树的函数
        def SearchTree(root, k):
            global num
            if root == None:
                return 
            res = SearchTree(root.left, k)
            #返回第k次访问的结点值
            if num == k:
                return res
            num += 1
            if num == k:
                return root.val
            return SearchTree(root.right, k) 
        return SearchTree(root, k)