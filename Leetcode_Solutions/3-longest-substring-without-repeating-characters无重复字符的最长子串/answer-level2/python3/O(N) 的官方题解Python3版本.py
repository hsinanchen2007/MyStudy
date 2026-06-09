## 思路
就是官方题解最后一个的Python版。设置一个变量i代表最大字串的起始位置，j是遍历的循环变量，ans代表最终长度。

设置了一个字典映射，键是str中出现的字符，值是这个键最后出现的位置加一。

实时的待定字符串就是s[i:j]

当j循环的时候，如果s[j]不在字典中或者s[j]在字典中但是它的位置出现在i之前，这就说明这个字符没有出现过待定字符串中，那么最终结果要增加，同时更新字典。

如果s[j]在字典中并且出现位置在i之后，这就说明这个字符出现在待定字符串中，那就需要把i更新到这个字符出现后的第一个位置，即字典中的值。

## 代码
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i,ans = 0, 0
        hash_dict = {}
        for j in range(len(s)):
            if hash_dict.get(s[j]) is not None and hash_dict.get(s[j]) > i:
                i = hash_dict.get(s[j])
            ans = max(ans, j - i + 1)
            hash_dict[s[j]] = j + 1
        return ans
```