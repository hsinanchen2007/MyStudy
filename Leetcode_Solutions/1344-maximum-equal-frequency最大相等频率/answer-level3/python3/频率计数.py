### 解题思路
-   从前向后遍历，我们通过频率出现的次数进行判定

当频率出现小于等于2的时候，可能出现满足结果的情况，这时候进行判定

有下面几种情况可以更新结果：

1.  如果目前只有一种频率，并且出现次数为1，肯定满足条件，这表示同一个数字出现了多次
2.  如果目前只有一种频率，但是出现了多次，频率为1，这时候也满足条件，表示多个数字都出现了一次
3.  如果目前有两种频率，并且低频率是1，出现了一次，就表示有一个额外的字母，删掉即可
4.  如果目前有两种频率，并且高频恰好比低频多1，并且高频出现次数是1，这时候高频的去掉一个字母，就变成了低频的，满足条件

### 代码

```python3
from collections import defaultdict


class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        count = defaultdict(int)
        freq_count = {}
        ans = 0

        for index, num in enumerate(nums):
            count[num] += 1
            freq = count[num]
            freq_count.setdefault(freq, 0)
            freq_count[freq] += 1
            if freq > 1:
                freq_count[freq - 1] -= 1
                if freq_count[freq - 1] == 0:
                    freq_count.pop(freq - 1)

            # 判定
            if len(freq_count) == 1:
                (x, y) = list(freq_count.items())[0]
                if x == 1 or y == 1:
                    ans = index + 1
            elif len(freq_count) == 2:
                (x, y), (x1, y1) = sorted(freq_count.items())
                if (x == 1 and y == 1) or (x1 == x + 1 and y1 == 1):
                    ans = index + 1

        return ans
```