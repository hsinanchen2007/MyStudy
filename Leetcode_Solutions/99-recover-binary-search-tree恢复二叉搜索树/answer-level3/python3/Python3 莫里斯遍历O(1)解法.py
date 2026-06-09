### 思路
思路是采用Morris中序遍历，保存前一个值`lastValue`和当前值`currentValue`，正常的话会是`lastValue < currentValue`如果`lastValue > currentValue`，我们知道这两个值是有问题的。
- 如果需要交换的值是相邻的，将有一个`drop`
- 如果不相邻，将有两个`drop`
```
 ... _ < _ < A > B < _ < _ ...
             ^^^^^
             drop 1
 ... _ < _ < A > B < _ < _ ...
 ... _ < _ < A > X < _ < Y > B < _ ...
             ^^^^^       ^^^^^
             drop 1      drop 2
```
这两种情况下我们都可以交换A和B
### 代码
```
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        cur,prev,drops = root,TreeNode(float('-inf')),[]
        while cur:
            if cur.left:
                temp = cur.left
                while temp.right and temp.right != cur:temp = temp.right
                if not temp.right:
                    temp.right,cur = cur,cur.left
                    continue
                temp.right = None
            if cur.val < prev.val:drops.append((prev,cur))
            prev,cur = cur,cur.right
        drops[0][0].val,drops[-1][1].val = drops[-1][1].val,drops[0][0].val
```
### 复杂度分析
- 时间复杂度：$O(N)$。我们遍历了整棵树
- 空间复杂度：$O(1)$。使用了`cur`,`prev`,`drops`