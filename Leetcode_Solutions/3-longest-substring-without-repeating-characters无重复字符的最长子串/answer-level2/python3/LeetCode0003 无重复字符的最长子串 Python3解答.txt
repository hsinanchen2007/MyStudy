
![image.png](https://pic.leetcode-cn.com/e2e80cc9f64dc3b3073dcbe9be7eb4f5598b471da047befc26113f4ff42c7102-image.png)
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        out = r = ""
        for x in s:
            if x not in r:
                r += x
            else:
                if len(out) < len(r):
                    out = r
                r += x
                m = r.index(x)
                r = r[m+1:]
        # 如果从头到尾没有出现重复字符，就需要再比较一次，因为循环内没有
        if len(out) < len(r):
            out = r
        return len(out) 
```