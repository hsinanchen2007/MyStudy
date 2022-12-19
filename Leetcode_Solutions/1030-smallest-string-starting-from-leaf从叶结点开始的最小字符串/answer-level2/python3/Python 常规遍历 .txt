这道题和 257 求二叉树的所有路径一样，需要求出所有的可能路径，
为了方便 数字和字母的对应，导入string 库 用到ascii_lowcase，函数。
利用python的自带sort函数，对 路径的逆序 进行排序。。默认按照字典序。
```
class Solution:
    def smallestFromLeaf(self, root: TreeNode) -> str:
        import string
        if not root:
            return ''
        res = []
        def find(root,path):
            if not root:
                return ''
            if not root.left and not root.right:
                res.append(path+string.ascii_lowercase[root.val])
            find(root.left,path+string.ascii_lowercase[root.val])
            find(root.right,path+string.ascii_lowercase[root.val])
        find(root,'')
        ###到这里为止，求出所有的路径 放进res list中。。

        res = [i[::-1] for i in res]
        print(res)
        return sorted(res)[0]
        

```
