输入：
"aewfafwafjlwajflwajflwafj"
["apple","ewaf","awefawfwaf","awef","awefe","ewafeffewafewf"]

输出："awefawfwaf"
预期："ewaf"

为啥在这个测试用例失败了？真正的答案不应该是"awefawfwaf"吗？

```python
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        char_nums = {}
        for c in s:
            if c not in char_nums:
                char_nums[c] = 1
            else:
                char_nums[c] += 1
        
        def has_string(string):
            sub_char_nums = {}
            for c in string:
                if c not in sub_char_nums:
                    sub_char_nums[c] = 1
                else:
                    sub_char_nums[c] += 1
            
            for k, v in sub_char_nums.items():
                if v > char_nums.get(k, 0):
                    return False
            return True
        
        d = sorted(d)
        
        str_max = ""
        for st in d:
            if has_string(st) and len(st) > len(str_max):
                str_max = st
        return str_max
```
