### 解题思路
同习题 [主站 113 题相同](https://leetcode-cn.com/problems/path-sum-ii/)
print(id(tmp))
print(id(tmp+[1]))

形成了一个新的对象, 较为耗时，必要时才用。例如[46 全排列](https://leetcode-cn.com/problems/permutations/)的时候返回值必须要用 tmp[:] liweiwei 的题解。

print(id(tmp))
print(id(tmp[:])) # 也生成了一个副本对象，相当于 tmp.copy()
 
python 函数调用，涉及到 list, 全是传的 list 的地址，会直接修改。
一般避免内部函数修改， 使用  

```python3
def f(a):
    a = a.copy()
    a.append(1)
    return a 
```

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
        def helper(root, tmp, rest): # root != None
            nonlocal res
            if not root.left and not root.right and rest == root.val:
                res.append(tmp+[root.val])  # 形成了一个新的对象,耗时 print(id(tmp)), print(id(tmp+[1]))
            else:
                if root.left:
                    helper(root.left, tmp+[root.val], rest-root.val)
                if root.right:
                    helper(root.right, tmp+[root.val], rest-root.val)
        res = []
        if root == None:
            return []
        helper(root, [], sum)
        return res
```