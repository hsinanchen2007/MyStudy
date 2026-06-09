```python
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        # order: str equal
        # s1.length, s2.length <= 1,000
        # ascii is lower
        # find the longest common string between two strings.
        # common string transfer to  dic
        # compute cost seperately
        # extra array: ascii array
        # abd
        # ba d

        # value [0, 196, 196]
        # value [194, 194, ]

        def common_string_val(s1, s2):
            l1, l2  = len(s1), len(s2)
            value = [[0] * l1 for _ in range(l2)]
            for i in range(l2): 
                for j in range(l1):
                    if i == 0 or j == 0:
                        value[i][j] =  2 * ord(s2[i]) if s2[i] == s1[j] else 0
                        if i != 0: value[i][j] = max(value[i - 1][j], value[i][j])
                        if j != 0: value[i][j] = max(value[i][j - 1], value[i][j])
                        continue
                    value[i][j] = max(value[i][j], value[i][j - 1], value[i - 1][j])
                    if s2[i] == s1[j]:
                        value[i][j] = max(value[i][j], 2 * ord(s2[i]) + value[i - 1][j - 1])
            return max([max(val) for val in value])
        
        def string_val(s):
            return sum([ord(ch) for ch in s])
        if s1 == '' or s2 == '':
            return string_val(s1) + string_val(s2)
        return string_val(s1) + string_val(s2) - common_string_val(s1, s2)


```