### 解题思路
![168_5293结果.png](https://pic.leetcode-cn.com/de7c7f4bc60783bac095a52295cb7a40f77140042d06b0730da5a5dda17d43e0-168_5293%E7%BB%93%E6%9E%9C.png)
# 最多重复的子串只与minSize有关

### 代码

```python
class Solution(object):
    def maxFreq(self, s, maxLetters, minSize, maxSize):
        """
        :type s: str
        :type maxLetters: int
        :type minSize: int
        :type maxSize: int
        :rtype: int
        """
        # 最多重复的子串只与minSize有关
        n = len(s)
        d = dict()
        for i in range(n - minSize+1):
            tmp = s[i:i+minSize]
            if len(set(tmp)) > maxLetters:
                continue
            if tmp not in d:
                d[tmp] = 0
            d[tmp] += 1

        maxCount = 0
        for k, v in d.items():
            if v > maxCount:
                maxCount = v

        return maxCount
```