说明：
del_node用于存储待搜索的节点
dfs函数用于搜索一个节点，将这个节点的子节点中是删除的节点删掉
如果搜索到一个节点是删除节点的时候，会判断它左右子节点是否存在，然后存入del_node中
一直搜索直到del_node为空就停止
```
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return root
        # 转为set查找更快
        to_delete = set(to_delete)
        # 存放答案
        ans = []
        # 存放需要搜索的节点
        del_node = [root]
        
        def dfs(root):
            # 节点是删除节点时
            if root.val in to_delete:
                # 如果节点有左右子节点，存入del_node
                if root.left:
                    del_node.append(root.left)
                if root.right:
                    del_node.append(root.right)
                # false表示是删除节点
                return False
            # 对左子树进行搜索
            if root.left:
                res = dfs(root.left)
                # 如果左子树是删除节点，则将左子树设置为None
                if not res:
                    root.left = None
            # 对右子树进行搜索
            if root.right:
                res = dfs(root.right)
                # 如果右子树是删除点解，则将右子树设置为None
                if not res:
                    root.right = None
            return True
        # 将所有点进行遍历
        while len(del_node)>0:
            node = del_node.pop(0)
            # 只有该点不是删除节点的时候才添加到ans中
            if dfs(node):
                ans.append(node)
        return ans
```
