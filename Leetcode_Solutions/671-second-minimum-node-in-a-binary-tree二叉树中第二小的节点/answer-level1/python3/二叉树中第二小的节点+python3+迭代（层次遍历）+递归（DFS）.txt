### 1.迭代，层次遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

比较暴力，直接层次遍历，记录不等于根节点的数值中的最小值。代码如下：
```
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        ans=[root]
        judge = root.val
        second = 1000000000000
        while ans:
            tmp,n = [],len(ans)
            for i in range(n):
                r=ans.pop(0)
                if r:
                    ans.append(r.left)
                    ans.append(r.right)
                    if r.val != judge:
                        second = min(second,r.val)
            
        return second if second != 1000000000000 else -1
```
#### 复杂度分析
__时间复杂度：__ O(n^2)

__空间复杂度：__ O(n)
### 2. 递归
思路比较清晰，如果当前节点大于根节点的值，则比较（当前节点，递归左节点，递归右节点），找到最小值；反之则递归左右子节点，找最小值（不等于根节点的值）。代码如下：
```
class Solution:
    def findSecondMinimumValue(self, root: TreeNode) -> int:
        judge = root.val
        def find(root):
            if not root:
                return 1000000000000
            if root.val == judge:
                return min(find(root.left),find(root.right))
            return min(root.val,find(root.left),find(root.right))
        second = find(root)
        return second if second !=1000000000000 else -1
```
#### 复杂度分析
__时间复杂度：__ O(n)

__空间复杂度：__ O(n)

如果不能找到值的范围的话，可以将不等于根节点值的数存储起来，找最小值。