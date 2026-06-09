### 解题思路
先按height排序，height相同则按weight排。
排序后只需对newweight序列求最长递增子序列即可。
有个疑问，height相等，但weight不同的人为什么可以算在同一个序列里面……题目不是要求两条件都满足严格递增吗？

---
已修改题解！将height递增排，weight递减排，可避免选到相同身高的元素。
### 代码

```python3
class Solution:
    def bestSeqAtIndex(self, height: List[int], weight: List[int]) -> int:
        hw = [(h, w) for h, w in zip(height, weight)]
        hw.sort(key=lambda x:(x[0], -x[1]))
        newweight = [a[1] for a in hw]
        tails, res = [0] * len(newweight), 0
        for num in newweight:
            i, j = 0, res
            while i < j:
                m = (i + j) // 2
                if tails[m] < num: i = m + 1
                else: j = m
            tails[i] = num
            if j == res: res += 1
        return res
```