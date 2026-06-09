### 解题思路
[参考题解](https://leetcode-cn.com/problems/path-sum-ii/solution/dfs-by-powcai-2/)

本题需要细细思考。
1. python 的全局变量
2. python 的append 和 copy
3. 是否在进入递归前，判断边界条件，还是进入后第一条判断边界条件。 
   这里是在进入更深一层的递归之前判断是否为 None, 但是我忘了考虑初始 root 可能就是 None，而函数内部也不判断是否为 None, 导致错误。 也可见 [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/solution/gelthin-dfs-by-gelthin/)
4. 这里的 root 是啥，为何放入 list 会直接报各种看不懂的错误。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ## 和上一题一样，只不过要在遍历过程中记录路径，要新增一个变量
        def helper(result, root, tmp, rest):
            if not root.left and not root.right and rest == root.val:
                # tmp += [root] ## BUG, 
                #直接报各种看不懂的错误，也不知道它这个 root 到底是啥，还是不是对象
                tmp += [root.val]
                result.append(tmp[:])  ## 这里进行一个 copy
            else:
                if root.left:
                    helper(result, root.left, tmp+[root.val], rest-root.val)
                if root.right:
                    helper(result, root.right, tmp+[root.val], rest-root.val)
        result = []  ## 全局变量
        if root== None:
            return []
        helper(result, root, [], sum)  ## 进入这一函数时必须要保证 root 非空，否则报错
        return result
```