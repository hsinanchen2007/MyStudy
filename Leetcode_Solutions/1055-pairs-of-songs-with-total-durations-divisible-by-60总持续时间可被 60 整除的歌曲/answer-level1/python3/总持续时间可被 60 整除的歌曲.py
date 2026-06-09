### 解题思路
不知道是从谁那抄的作业了。。。不知道为什么大佬们总是能解决超时问题。。。

### 代码

```python3
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        pos = [0] * 60
        res = 0
        for t in time:
            t %= 60
            res += pos[-t]
            pos[t] += 1
        return res 

        # 方法1: 在第31个测试用例会超时
        # count = 0
        # mod = []
        # length = len(time)
        # for i in range(length):   # 求出所有的mod余数
        #     mod.append(time[i] % 60)

        # for i in range(length-1):
        #     adver = 60 - mod[i]
        #     count += mod[i+1:].count(adver)   # 找到对应的“60的补数”个数
        
        # zero = mod.count(0)   # 特殊处理 余数为0的时间
        # count += (zero * (zero -1) // 2)
        # return count

                


```