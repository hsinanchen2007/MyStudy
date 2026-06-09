### 迭代法
如果是对称二叉树，则每一层都应该是对称的，因此可以通过层次遍历，判断每一层是不是对称。代码如下：
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        ans = [root.left,root.right]
        while ans:
            tmp,n= [],len(ans)
            for i in range(n):
                r = ans.pop(0)
                if r:
                    ans.append(r.left)
                    ans.append(r.right)
                    tmp.append(r.val)
                else:
                    tmp.append(None)
            if not self.judge(tmp):
                return False   
        return True
    def judge(self,tmp):
        m = len(tmp)
        if m%2 !=0:
            return False
        for i in range(m//2):
            if tmp[i] != tmp[m-i-1]:
                return False
        return True
```
#### 复杂度分析
__时间复杂度：__ O(n^2)，因为判断是否对称的辅助函数judge的复杂度也为O(n),所以总体上应该是O(n^2)的层级

__空间复杂度：__ O(n)