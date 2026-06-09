```
class Solution:
    def lengthOfLongestSubstringTwoDistinct(self, s: str) -> int:
        freqDict = {}
        windowStart, maxLen = 0, 0
        for windowEnd in range(len(s)):
            # 扩大滑动窗口
            rightChar = s[windowEnd]
            if rightChar not in freqDict:
                freqDict[rightChar] = 0
            freqDict[rightChar] += 1
            # 收缩滑动窗口直到满足只含有两个字符
            while len(freqDict) > 2:
                leftChar = s[windowStart]
                windowStart += 1
                if leftChar in freqDict:
                    freqDict[leftChar] -= 1
                    if freqDict[leftChar] == 0:
                        del freqDict[leftChar]
            maxLen = max(maxLen, windowEnd - windowStart + 1)
        return maxLen
```
