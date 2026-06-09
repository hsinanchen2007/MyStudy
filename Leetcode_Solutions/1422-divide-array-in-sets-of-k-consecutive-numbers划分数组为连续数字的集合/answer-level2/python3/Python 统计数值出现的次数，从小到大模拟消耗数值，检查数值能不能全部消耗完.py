![image.png](https://pic.leetcode-cn.com/b9524d997d24342f193507437bb7b295a6149eedf96afd6bade787d43ff0b3a7-image.png)


```
'''
统计每一个数字出现的次数，从小到大枚举出现过的数值，每次迭代
到的数值后面连续k-1个数值一定要是存在且数量比当前数值多，否则
当前数值的个数不可能被消耗完，如果所有数值全部能消耗完，即返回
True
'''


from typing import List

from collections import Counter
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        c = Counter()
        for val in nums:
            c[val] += 1

        all_vals = sorted(list(c.keys()))

        for val in all_vals:
            if c[val] == 0:
                continue

            min_cnt = c[val]
            for next in range(val+1, val + k):
                if next not in c or c[next] < min_cnt:
                    return False

            for v in range(val, val+k):
                c[v] -= min_cnt

        return True
```
