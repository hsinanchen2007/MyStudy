满足条件 -> 扩张长度1，不满足条件 -> 滑动
保存滑动窗口内相同字母出现次数的历史最大值，
通过判断窗口宽度(right - left + 1) - maxFreq > K来决定窗口是否做滑动，否则窗口就扩张
这里只需要记录历史最大值的原因是我们只需要最终保证输出的是最大长度，无需缩减窗口大小
```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        from collections import defaultdict
        # 动态滑动窗口
        maxLen, windowStart, maxFreq = 0, 0, 0
        # 统计出现频率
        freqDict = defaultdict(int)
        for windowEnd in range(len(s)):
            rightChar = s[windowEnd]
            freqDict[rightChar] += 1
            # 保存历史出现的最大频率
            maxFreq = max(freqDict[rightChar], maxFreq)
            # 缩小滑动窗口
            if (windowEnd - windowStart + 1 - maxFreq) > k:
                leftChar = s[windowStart]
                windowStart += 1
                freqDict[leftChar] -= 1       
            maxLen = max(maxLen, windowEnd - windowStart + 1)
        return maxLen
```