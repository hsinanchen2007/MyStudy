![image.png](https://pic.leetcode-cn.com/e950eb5e661bb06407e1bbb8933f46e9ac3c8311866a4ee552d1ff826a6cfc66-image.png)

```
'''
贪心策略，把value全部按照数值降序排，从大到小
选数据，只要这个数据对应的label计数值不超过use_limit
就可以进行选择， 直到遍历结束或者是数量选够为止

'''

from typing import List
from collections import Counter

class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        l = [(val, label) for val, label in zip(values, labels)]
        l.sort(reverse = True)

        c = Counter()
        cnt = 0
        sum = 0
        for val, label in l:
            if cnt == num_wanted:
                break

            if c[label] < use_limit:
                c[label] += 1
                sum += val
                cnt += 1

        return sum
```
