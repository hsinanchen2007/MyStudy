![image.png](https://pic.leetcode-cn.com/e60590f330e7f7b178d69eb68e83eab6a2811029a9dcd586262f044c83ede1be-image.png)



```
'''
对出现过的数值进行个数计数，优先选数量多的数字，对选中
数值的个数进行累加，直到累加和大于等于总个数一半，返回
选中的数字个数
'''


from typing import List
from collections import Counter
class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        c = Counter(arr)
        l = sorted(list(c.values()), reverse = True)

        total_cnt = 0
        ans = 0
        target = (len(arr) // 2) + (len(arr) & 1)
        for cnt in l:
            if total_cnt >= target:
                break

            total_cnt += cnt
            ans += 1

        return ans
```
