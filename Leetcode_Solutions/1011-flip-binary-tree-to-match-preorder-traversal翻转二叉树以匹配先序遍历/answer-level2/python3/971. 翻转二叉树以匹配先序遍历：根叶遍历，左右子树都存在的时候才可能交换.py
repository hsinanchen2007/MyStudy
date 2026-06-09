![image.png](https://pic.leetcode-cn.com/0eae90b8fabcd9fff225d2f5b447be88e531c7b3ec47c74e7e791beabfe995b6-image.png)

原则上是根左右前序遍历，当左右子树都存在且左子树的值不等于下一个前序遍历的值时，才变成根右左遍历，实质进行交换。

通过一个flag全局记录出现无法匹配的情况，顺带剪枝，且最后由flag来决定输出。

```python []
class Solution:
    def flipMatchVoyage(self, root: TreeNode, voyage: List[int]) -> List[int]:
        ans, flag = [], True
        def f(r):
            nonlocal ans, flag
            if r and flag:
                if not voyage or r.val != voyage.pop(0):    #如果树存无数列或当前树值无法匹配数列首元素，就更改flag
                    flag = False
                elif r.left and r.right and r.right.val == voyage[0]:   #如果两子树都存在且左子树值不等于数列的首元素，就交换遍历顺序
                    ans += [r.val]
                    f(r.right); f(r.left)
                else:                                       #其他情况正常遍历
                    f(r.left); f(r.right)
        f(root)
        return ans if flag else [-1]    #其实还应该保数列不会超长，但似乎系统检验不对此做出检验，所以就不加and not voyage了
```
