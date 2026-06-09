思路：
1、新建一个数组temp保存秒数模60相等的项的个数，总对数初始为0；
2、遍历数组time，总对数加上temp[(60 - time[i] % 60) % 60]，填充数组temp。

```
class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        n = 0;
        temp = [0]*60
        for i in range(len(time)):
            n += temp[(60 - time[i] % 60) % 60]
            temp[time[i] % 60] += 1
            pass
        return n
```
