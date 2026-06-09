```python
class Solution:
    # Time complexity: O(N)
    # Space complexity: O(1)
    def characterReplacement(self, s: str, k: int) -> int:
        char_table = [0] * 26

        # Time complexity :O(26) => O(1)
        def check(char_table: List[int], k: int) -> bool:
            max_value = max(char_table)
            sum_value = sum(char_table)
            return sum_value - max_value <= k

        res, j = 0, 0
        #O(n)
        for i in range(len(s)):
            char_table[ord(s[i]) - ord('A')] += 1
            while j < len(s) and not check(char_table, k):                
                char_table[ord(s[j]) - ord('A')] -= 1
                j += 1
            res = max(res, i + 1 - j)
        return res
```