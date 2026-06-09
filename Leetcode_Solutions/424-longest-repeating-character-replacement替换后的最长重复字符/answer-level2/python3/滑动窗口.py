### 解题思路
max_value + k >= right - left + 1

### 代码

```python3
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if not s:
            return 0
        left, right = 0, 0
        max_len = float('-inf')
        key_hash = {}
        flag = False
        while right < len(s):
            if key_hash.get(s[right]) and flag is False:
                key_hash[s[right]] += 1
            elif not key_hash.get(s[right]) and flag is False:
                key_hash[s[right]] = 1
            max_value = sorted(key_hash.values(), reverse=True)[0]
            if right >= len(s):
                break
            if max_value + k >= right - left + 1:
                max_len = max(max_len, right - left + 1)
                right += 1
                flag=False

            else:

                key_hash[s[left]] -= 1
                left += 1
                flag = True

        return max_len
```