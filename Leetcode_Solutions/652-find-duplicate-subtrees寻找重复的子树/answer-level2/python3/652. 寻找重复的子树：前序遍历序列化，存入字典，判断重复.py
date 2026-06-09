![image.png](https://pic.leetcode-cn.com/0833994ee69dd160794fb50144a2f268295c1783880334095e214f3ac17e87d8-image.png)

```python []
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        ans, d = [], {}
        def f(r):
            if not r:
                return 'N'
            s = str(r.val) + ' ' + f(r.left) + ' ' + f(r.right)
            if s not in d:
                d[s] = True
            elif d[s]:
                ans.append(r)
                d[s] = False
            return s
        f(root)
        return ans
```
估计对时间影响最大的还是序列长度，给一个理论上不一定是完美（我也不懂证明），但又可以AC的代码吧（其实就是删掉了序列不同值之间的间隔而已）

![image.png](https://pic.leetcode-cn.com/a585f9a8eeafa9c4582b96412b271617431f984e49b33724693ad21a51830565-image.png)

```python []
class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        ans, d = [], {}
        def f(r):
            if not r:
                return ' '
            s = str(r.val) + f(r.left) + f(r.right)
            if s not in d:
                d[s] = True
            elif d[s]:
                ans.append(r)
                d[s] = False
            return s
        f(root)
        return ans
```


