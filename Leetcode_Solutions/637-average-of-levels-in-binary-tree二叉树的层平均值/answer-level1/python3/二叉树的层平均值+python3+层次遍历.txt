### 层次遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

这题与[二叉树层次遍历II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/solution/er-cha-shu-de-ceng-ci-bian-li-iipython3ceng-ci-bia/) 类似，可以参考一下，思路还算比较清晰。代码如下：

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        ans = [root]
        target = []
        while ans:
            n = len(ans)
            tmp,sum_= [],0
            for i in range(n):
                r =ans.pop(0)
                sum_+=r.val
                if r.left:
                    ans.append(r.left)
                if r.right:
                    ans.append(r.right)
            target.append(sum_/(i+1))
        return target
```