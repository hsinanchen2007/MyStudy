![image.png](https://pic.leetcode-cn.com/4a57cb6a72d73287b323d2e92eb739118e20330de54a035e1d8462f2f604e308-image.png)


```
'''
贪心策略
想象一下每个数值的贡献，正数直接给最后的总和增加价值，越大的数放后面越有利，
所以先对列表降序排序，先遍历正数，然后遍历负数，遇到正数直接放到答案序列最
左边
而负数加入虽然会首先让总和减少，但是会让数值比它大的值往后面移动一格，又可以
让总和增加，所以负数的共享有两部分，如果这两部分总体加起来是正的，那负数就
可以加到当前序列的最左边，否则如果加入队列，会让总和减小，即使是让总和保持
不变，继续加下一个小于等于当前值的负值，必然会继续让总和减少，不可能产生更大
的和，这时迭代停止，当前累加值就是最大和
'''

from typing import List
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        s = satisfaction
        s.sort(reverse=True)

        cur_sum = 0     # 当前已近看到过的数值的累加和
        total = 0
        for val in s:
            if cur_sum + val <= 0:
                break

            # 已经存在的值全部右移动一格，总和增加cur_sum，还要加上新加入的val * 1
            total += cur_sum + val
            cur_sum += val

        return total
```
