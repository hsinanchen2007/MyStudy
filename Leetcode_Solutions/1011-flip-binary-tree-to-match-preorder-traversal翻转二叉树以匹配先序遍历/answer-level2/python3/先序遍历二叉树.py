### 解题思路
res = []
res为结果列表

先序遍历二叉树，对于遍历到的结点node:
1）if node.val != voyage[0] 则：无法翻转，结果为[-1]
2）如果 voyage.length = 1: 则说明遍历到了最后一个结点，可直接返回
3）如果 node.left != None 则：
	 如果 node.left.val != voyage[1] 且 node.right != None 且 node.right.val  == voyage[1] 则：交换当前结点的左右子
	 voyage = [1:]
	 对node.left 从1）开始执行
4）如果 node.right != None 则：
	 voyage = [1:]
	 对node.right 从1）开始执行
### 代码

```python3    
class Solution:
    def flipMatchVoyage(self, root: TreeNode, vy: List[int]) -> List[int]:
        if not root: return []
        if root.right == root.left == None: return []
        result = []
        flag = True

        def dfs(rt):
            nonlocal result, flag,  vy
            if vy == []: return
            if rt.val != vy[0]:
                flag = False
                return
            if len(vy) == 1: return
            if rt.left != None:
                if rt.left.val != vy[1] and rt.right != None and rt.right.val == vy[1]:
                    rt.left, rt.right = rt.right, rt.left
                    result.append(rt.val)
                vy = vy[1:]
                dfs(rt.left)
            if rt.right != None:
                vy = vy[1:]
                dfs(rt.right)
        dfs(root)
        if not flag: return [-1]
        return result

```



