### 解题思路
递归，通过拷贝避免回溯，递归过程中记录路径以及结果集。

### 时间复杂度
O(N): 一次遍历所有节点。

### 空间复杂度
O(N^2)：每次递归都需要拷贝一次路径。当二叉树退化为链表时，路径最深。

### 测试点
[1,-1,-1]
0
[1,1,1]
2
[5,4,8,11,null,13,4,7,2,null,null,5,1]
22
[1,2]
1
[]
1
[1]
1
[1]
0

### 代码
```python3
class Solution:
    def pathSumCore(self, root: TreeNode or None, target: int, path: [], ans: List[List[int]]):
        if root is None or root.val is None:
            return

        is_leaf = root.left is None and root.right is None
        current_path = path + [root.val]
        if is_leaf and sum(current_path) == target:
            ans.append(current_path)

        self.pathSumCore(root.left, target, path + [root.val], ans)
        self.pathSumCore(root.right, target, path + [root.val], ans)

    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        ans = []
        self.pathSumCore(root, target, [], ans)
        return ans
```