本题解参考自原书题解。

本题的难点在于二叉搜索树可以对应多个序列，因此从一些基本情况来枚举看看情况是比较好的思路。

首先从最简单的示例看看：
```
        2
       / \
      1   3
```
返回
```
[
   [2,1,3],
   [2,3,1]
]
```
由于是从数组中从左到右插入元素到二叉搜索树中，因此每个元素在已存在的二叉搜索树中的插入位置都是确定的。

可得结论：
1. **数组的第一个元素，必定对应于二叉搜索树的树根**。
2. **一个节点对应的子节点在序列上必定在父节点元素之后**，如上图子节点1、3在输出的序列中必定在父节点2之后。
猜想：各个序列的差异主要是子树的插入顺序不同，例如此例子可以对应先插左子树后插右子树，或者是先插右子树再插左子树。

得出基本结论后继续看看复杂一些的例子：
```
        2
       / \
      1   4
         /
        3
```
返回
```
[
   [2,1,4,3],
   [2,4,1,3],
   [2,4,3,1]
]
```
从本例来看，`各个序列的差异主要是子树的插入顺序不同`这一猜想不正确。插入的顺序可能是先插部分左子树节点，再插部分右子树节点。
并且插入的顺序始终不会违反结论2，节点3在序列中的位置必定在父节点4之后，因此可以说明**序列中子树节点的相对顺序是可以确定的**。

因此我们将子树中的节点看做单个序列，如上例中左边的序列为{2},右边的序列为{4,3}，将两个序列按照相对顺序进行混合：
```
[
   [1,4,3],
   [4,1,3],
   [4,3,1]
]
```
如果此时再在各个序列中加上父节点生成的前缀2，恰好对应了答案。

因此只需递归地找到每个节点对应生成的序列，再在父节点进行混合，即可得到答案。代码如下：
```
class Solution:
    def BSTSequences(self, root: TreeNode) -> [[int]]:
        def merge(left, right, tmp, result, prefix):
            """
            在保持相对顺序下合并left与right并添加prefix，如[1,2][4,5] ->
            [[0, 1, 2, 4, 5], [0, 1, 4, 2, 5], [0, 1, 4, 5, 2], [0, 4, 1, 2, 5], [0, 4, 1, 5, 2], [0, 4, 5, 1, 2]]
            """
            if len(left) == 0 and len(right) == 0:
                result.append([prefix] + tmp[:])

            if len(left) > 0:
                tmp.append(left[0])
                merge(left[1:], right, tmp, result, prefix)
                tmp.pop()

            if len(right) > 0:
                tmp.append(right[0])
                merge(left, right[1:], tmp, result, prefix)
                tmp.pop()

        def dfs(root):
            if root.left and root.right:
                left = dfs(root.left)
                right = dfs(root.right)
                cur_seq = []
                for l in left:
                    for r in right:
                        merge_result = []
                        merge(l, r, [], merge_result, root.val)
                        cur_seq.extend(merge_result)

                return cur_seq
            
            elif root.left:
                left = dfs(root.left)
                return [[root.val] + l for l in left]
            
            elif root.right:
                right = dfs(root.right)
                return [[root.val] + r for r in right]      
            
            return [[root.val]]

        if root is None:
            return [[]]
        return dfs(root)
```











