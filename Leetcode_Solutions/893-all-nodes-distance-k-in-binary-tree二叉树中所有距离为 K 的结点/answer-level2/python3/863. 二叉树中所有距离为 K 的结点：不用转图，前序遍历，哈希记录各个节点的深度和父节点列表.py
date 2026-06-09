![image.png](https://pic.leetcode-cn.com/498d84d5edc7e155a7b107b05da32f4d78110ee4dae5a54462090107edfab28c-image.png)

前序遍历，哈希记录各个节点的深度和父节点集合。

节点a与节点b的最近公共父节点为c，h为节点的深度，则a与b的距离为$distance(a,b)=h(a)+h(b)-2*h(c)$

依据这个公式再遍历一次树就可以了，满足条件的就输出。

```python []
class Solution:
    def distanceK(self, root, target, K):
        h, f = {}, {}
        def g(r, i, fs):
            if r:
                h[r.val] = i
                f[r.val] = [r.val] + fs     #让最近的父节点排在最前面
                g(r.left, i + 1, f[r.val])
                g(r.right, i + 1 , f[r.val])
        g(root, 0, [])
        ans, ft, ht = [], set(f[target.val]), h[target.val]
        for i in h:
            for common in f[i]:             #由近到远遍历目标点的父节点
                if common in ft:            #如果存在共同父节点且满足条件
                    if ht + h[i] - 2 * h[common] == K:
                        ans += [i]          #就加入答案
                    break
        return ans
```
