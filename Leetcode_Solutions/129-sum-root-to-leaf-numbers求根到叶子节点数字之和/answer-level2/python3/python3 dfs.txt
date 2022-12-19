dfs遍历每个路径，其中用字符串连接与转换的方式，将每个路径的值放在列表中，求和列表得到结果

```
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root: return 0
        res = []
        def dfs(node,tmp,res):
            if not node: return                         #当树中的节点出现只有左子树或右子树的情况，这一句保证下一句不出错。
            if not node.left and not node.right:        #判断当前结点是否为叶子结点，是的话返回值，加入到res列表中
                res.append(int(tmp+str(node.val)))
                return
            tmp += str(node.val)
            dfs(node.left,tmp,res)
            dfs(node.right,tmp,res)
        dfs(root,'',res)
        return sum(res)
```
