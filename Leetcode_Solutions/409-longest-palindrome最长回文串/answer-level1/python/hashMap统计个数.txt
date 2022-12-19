### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        # 只用输出他们的个数
        hash_map = {}
        for c in s:
            if c not in hash_map:
                hash_map[c] = 1
            else:
                hash_map[c] += 1
        odd = 0
        count = 0
        for item in hash_map.items():
            if item[1] % 2 == 0:
                count += item[1]
            else:
                count += 2 * (item[1] // 2)
                odd += 1
        return count + 1 if odd > 0 else count
```