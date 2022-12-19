### 解题思路
动态规划问题
![image.png](https://pic.leetcode-cn.com/e773dc9df417b3e85939c0383301f41c95caccac8844ec161bf65efbdf8dd718-image.png)



### 代码

```python
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """

        g = [0] * (n+1)
        g[0], g[1] = 1, 1

        for i in range(2, n+1):
            for j in range(1, i+1):
                g[i] += g[j-1] * g[i-j]

        return g[n]
```