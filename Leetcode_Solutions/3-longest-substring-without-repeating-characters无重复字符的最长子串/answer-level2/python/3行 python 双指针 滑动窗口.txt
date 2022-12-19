```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i, r, d = 0, 0, {}
        for j, c in enumerate(s): i, r, d[c] = max(i, d.get(c, -1) + 1), max(r, j - i), j
        return max(r, len(s) - i)
```
- 双指针滑动窗口
- i 代表起始位置，r 记录最优解，d 是一个字典，记录所有字符最后出现的位置
- 每次迭代过程中，遇到遇见过的字符时，i 就会变为那个字符上一次出现位置 + 1，r 记录上一次应该达到的全局最大值，所以最后需要再比较一次