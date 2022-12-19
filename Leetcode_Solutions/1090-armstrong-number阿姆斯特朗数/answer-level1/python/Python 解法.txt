## 思路

先通过把N转字符串并取长度的方法找到题目描述中的k，

然后提取N的每一位上的数字，并将其的k次幂累加在一起，

最后判断累加和是否等于原来的输入N。

## Python代码
```Python
class Solution(object):
    def isArmstrong(self, N):
        """
        :type N: int
        :rtype: bool
        """
        k = len(str(N))
        n = N
        s = 0
        while N:
            N, tmp = divmod(N, 10) #取出每一位上的数字，并放到tmp里
            s += tmp ** k
        return s == n
```

## 复杂度分析：

时间复杂度：$O（logN）$

空间复杂度：$O(1)$