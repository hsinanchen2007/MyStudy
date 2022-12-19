### 层次遍历
**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**

思路：逐层遍历，再反转数组
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        ans = [root]
        target = []
        while ans:
            tmp,n = [],len(ans)
            for i in range(n):
                r = ans.pop(0)
                tmp.append(r.val)
                if r.left:
                    ans.append(r.left)
                if r.right:
                    ans.append(r.right)
            target.append(tmp)
        return target[::-1]
        
```
#### 复杂度分析
__时间复杂度:__ 最差O(n^2)，for循环O(n)，pop操作O(n)

__空间复杂度：__ O(n)，tmp, ans,target数组的空间均不超过O(n)

### 递归
改成了递归，不过好像没啥意义，空间复杂度还变高了...
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        ans = [root]
        target = []
        
        def subfunc(ans):
            tmp = []
            n = len(ans)
            for i in range(n):
                r = ans.pop(0)
                tmp.append(r.val)
                if r.left:
                    ans.append(r.left)
                if r.right:
                    ans.append(r.right)
            target.append(tmp)
            if ans == []:
                pass
            else:
                subfunc(ans)
        subfunc(ans)
        return target[::-1]
```