一开始做的时候没想到好的解法，看了大佬们的解法讨论后用python实现,但是python标准库中没有TreeMap，只好用Sort + OrderedDict来替代


解法：
连续数字的集合实际上等于一条条的线段，那么，如果将每个点的出现次数统计，然后从最小的点开始为其寻找连续的k个点来组成线段，如果无法找到连续的k个点，则返回False。



```
from collections import OrderedDict
class Solution:
    def isPossibleDivide(self, nums: [int], k: int) -> bool:
        if len(nums) % k != 0:
            return False

        # 由于python中没有treemap，因此先排序再使用orderDict来替代
        nums.sort()
        d = OrderedDict()
        for num in nums:
            d[num] = d.get(num, 0) + 1
        
        # print(d)
        for key, val in d.items():
            while val != 0:
                for i in range(1, k):
                    nxt_key = key + i
                    if nxt_key not in d or d[nxt_key] == 0:
                        return False
                    d[nxt_key] -= 1
                val -= 1
        
        return True
```

时间复杂度O(nlogn) 空间复杂度O(n)