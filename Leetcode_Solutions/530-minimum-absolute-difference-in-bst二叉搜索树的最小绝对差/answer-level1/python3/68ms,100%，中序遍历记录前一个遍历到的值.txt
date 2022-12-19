![image.png](https://pic.leetcode-cn.com/e65a5c1f4e562818f46f6d688a5b80901db5905f90a8d9548e63008001c225d5-image.png)

中序遍历的同时，记录前一个遍历到的值，现值和前一个遍历到的值做差，然后记录全局最小差，时间O(n)，空间O(1)
```
class Solution:
    def getMinimumDifference(self, root: TreeNode) -> int:
        ans=float('inf')
        pre=-ans
        def f(r):
            nonlocal ans,pre
            if not r:
                return
            f(r.left)
            if r.val-pre<ans:
                ans=r.val-pre
            pre=r.val
            f(r.right)
        f(root)
        return ans
```
