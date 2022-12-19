二叉树的问题基本都是递归解决的。按照题目意思要找到所有到叶子节点的路径的和。因此肯定要遍历这颗二叉树。二叉树有三种遍历方式。根据题目意思，显然是先序遍历的思路。遍历的时候用tmp_sum记录之前生成的数字。tmp_sum的更新为  tmp_sum = tmp_sum*10 + curr_val。res数组用来记录所有路径的数字。

```python []
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        #用来记录各个路径的结果
        self.all_num = []
        res = 0
        def helper(node,tmp_sum):
            if not node:
                return
            #此时为叶子节点
            if not node.left and not node.right:
                self.all_num.append(tmp_sum*10+node.val)
            
            #根据题目意思选择先序遍历
            helper(node.left,tmp_sum*10+node.val)
            helper(node.right,tmp_sum*10+node.val)
        
        helper(root,0)
        for item in self.all_num:
            res += item
        return res
```

