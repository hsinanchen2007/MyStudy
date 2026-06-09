```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        b, m, d = 0, 0, {}
        for i, l in enumerate(s): b, m, d[l] = max(b, d.get(l, -1) + 1), max(m, i - b), i
        return max(m, len(s) - b)
```
b代表起始位置，m代表上一步的最大无重复子串，d是一个字典，记录着到当前步骤出现过的字符对应的最大位置

每次迭代过程中，遇到遇见过的字符时，b就会变为那个字符上一次出现位置+1，m记录上一次应该达到的全局最大值，所以最后需要再比较一次