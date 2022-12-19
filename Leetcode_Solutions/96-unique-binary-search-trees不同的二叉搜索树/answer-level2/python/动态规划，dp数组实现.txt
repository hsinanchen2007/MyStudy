### 解题思路
遍历以1为根，2为根。。。k为根的情况
f(k)表示k 个节点构成搜索树的方法。 以j为根，1~j-1 构成左子树，j+1~k构成右子树
![1.jpg](https://pic.leetcode-cn.com/08bc715c59624af7b49291a754dd8713563bbb628bdbeec118a533e64551afd0-1.jpg)


### 代码

```python
"""
f(0) = 1
f(1) = 1
f(2) = 2
f(k) = sum(f(i)*f(k-1-i))(i =0 ...k-1)
"""
class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [-1] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for k in range(2, n + 1):
            sum = 0
            for i in range(0, k ):
                sum += dp[i] * dp[k - i - 1]
            dp[k] = sum
        print(dp[n])
        return dp[n]


if __name__ == "__main__":
    solution = Solution()
    solution.numTrees(4)
```