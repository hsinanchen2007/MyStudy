### 思路
复习一下中学数学 等差数列 求和公式
**S = n * a1 + d * n * (n-1) / 2**
其中S：总和  n：项数  a1:首项  d：公差
对于这道题d就是1，S就是target，我们要做的就是求当n=2...时，首项a1为正整数的所有情况
整理上面的公式：
**a1 = (2 * target + n - n^2) / 2n**
我们让n从2开始递增，观察等号右边是否为整数，如果是，则确定了一个以a1为首项，n为项数，其和为target的连续正整数数列，将它生成并放入结果中
可以发现随着n的增加，a1是会减小的（n的二次方比n跑得快），当a1减到0以下后，就不需要再继续了

### 代码
```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        n = 2
        while True:
            child = 2*target + n - n*n
            if child <= 0:
                break
            mother = 2*n
            if child % mother == 0:
                a = int(child / mother)
                list = []
                for i in range(0, n):
                    list.append(a)
                    a += 1
                res.insert(0, list)
            n += 1
        return res
```
一直都是拿Java在刷，这次改用Python，还不太熟悉，所以code的风格可能会比较奇怪。。

