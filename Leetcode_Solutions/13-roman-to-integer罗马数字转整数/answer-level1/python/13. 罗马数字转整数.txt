```
class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        # 罗马数字的规律：
        # 倒过来看，如果这一位数字比前一位大，就加；如果比前一位小，就减。最后取总和。
        
        mapping = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res, p = 0, 'I'
        
        for c in s[::-1]:
            res, p = res + mapping[c] if mapping[c] >= mapping[p] else res - mapping[c], c
        return res
```
