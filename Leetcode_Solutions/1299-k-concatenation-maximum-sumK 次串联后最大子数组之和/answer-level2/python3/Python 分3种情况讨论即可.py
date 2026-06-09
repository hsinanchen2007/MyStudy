![image.png](https://pic.leetcode-cn.com/332ed319acb6ec7f4a0385cb1a626de7e20d0e59c40ef9763f641537b7cb1ae6-image.png)


```
'''
分情况讨论
如果k == 1那只可能在arr自身里面找最大和子串
如果k == 2， 在arr复制一倍长度后找最大和子串
k > 2情况下，就是k==2 求出来的子串, 如果sum(arr)是大于0的，那么中间再穿插上k-2个连续的arr就是最终答案
'''

from typing import List
class Solution:
    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        l = arr*2 if k >= 2 else arr
        prev_min_val = 0    # 前面已经出现过的最小累加和

        total = 0
        max_sum = 0
        for val in l:
            total += val
            if total > 0:
                total %= 1000000007

            max_sum = max(max_sum, total - prev_min_val)
            prev_min_val = min(prev_min_val, total)

        if k > 2 and sum(arr) > 0:
            max_sum += ((sum(arr)%1000000007) * (k - 2)) % 1000000007
        return max_sum % 1000000007
```
