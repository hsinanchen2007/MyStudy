![image.png](https://pic.leetcode-cn.com/1ce50ab293c77e317a0f8f66160ff681627b06b0c7a91ce3562da58a02e26c3c-image.png)


根右左遍历，覆盖得到最每层最左侧的树值，并按层存进字典，然后输出字典最后一个值

时间O(n)，空间O(h)，最坏O(n)，好在不用做多余的判断，直接赋值就完事了

```
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        d={}
        def f(r,i):
            if r:
                d[i]=r.val
                f(r.right,i+1)
                f(r.left,i+1)
        f(root,0)
        return list(d.values())[-1]
```

O(1)空间的版本，也很快，不过神奇的是，测出来的空间是一样的，说明按层存字典没啥本质影响，但最慢的时候能到112ms左右，比前面的方法不稳定多了，原因未知，可能是测试服务器的问题。

![image.png](https://pic.leetcode-cn.com/183373aedd0dc982bc04ba5e9f5d911fb8b040f6d0c717de59ba898e61df11fd-image.png)


```
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        h,ans=0,0
        def f(r,i):
            if r:
                nonlocal h,ans
                if i>=h:
                    h=i
                    ans=r.val
                f(r.right,i+1)
                f(r.left,i+1)
        f(root,0)
        return ans
```
