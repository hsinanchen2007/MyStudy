思路
本题可以利用动态规划的方法快速实现，重点在于如何得到如下递推公式：
![递推公式1.png](https://pic.leetcode-cn.com/5ebddbd8f05b16628b0045ecdbe894f6fe9b37429887d5472e47c7b63a997eed-%E9%80%92%E6%8E%A8%E5%85%AC%E5%BC%8F1.png)

由题意，详细推导过程如下：
![公式推导.png](https://pic.leetcode-cn.com/45cb86577d4a0adf9ba7b4de5dd4c7f7b555771dfc33a1fa89739eee477042cd-%E5%85%AC%E5%BC%8F%E6%8E%A8%E5%AF%BC.png)
分析：时间复杂度O(N),空间复杂度O(1)
python实现：
```
class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        if A is None:
            return None
        if len(A) <= 1:
            return 0

        n = len(A)
        sumA = 0
        Fcur = 0  # 当前F值
        for i, v in enumerate(A):
            sumA += v
            Fcur += i * v
        Fmax = Fcur

        for j in range(1, n):
            tmp = A[-j]  # 最后一个元素
            Fcur += - n * tmp + sumA  # 更新当前Fcur的值
            if Fcur > Fmax:
                Fmax = Fcur

        return Fmax
```
效果
![运行结果.png](https://pic.leetcode-cn.com/8c2affa5ba57bdd3e92edf7933ac20375c4b5b59b7e80dc6ae4381d6a6164e5d-%E8%BF%90%E8%A1%8C%E7%BB%93%E6%9E%9C.png)


