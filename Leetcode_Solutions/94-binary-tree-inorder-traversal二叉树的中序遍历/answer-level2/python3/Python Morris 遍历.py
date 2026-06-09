```
注意第一遍查找，是为了构建右指针，所以会有个continue ，从这里区分是不是第一次经历到该节点
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        tmp = root
        res = []
        while tmp:
            if tmp.left:
                pre  = tmp.left
                while pre.right and pre.right != tmp:
                    pre = pre.right
                if not pre.right :
                    pre.right = tmp
                    tmp = tmp.left
                    continue
                res.append(tmp.val)
                tmp = tmp.right
            else:
                res.append(tmp.val)
                tmp = tmp.right
        return res

```
