### 解题思路
1. 枚举，枚举所有的前缀去判断是否存在这个最长前缀
2. 通过直接取两个字符串的公约数来判断是否满足要求
3. 数学方法我是看官方题解才看懂了，完全没想到，战术后仰

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # for i in range(min(len(str1), len(str2)), 0, -1):
        #     if len(str1) % i == 0 and len(str2) % i == 0:
        #         if str1[:i] * (len(str1) // i) == str1 and str1[:i] * (len(str2) // i) == str2:
        #             return str1[:i]
        # return ''

        # candidate_len = math.gcd(len(str1), len(str2))
        # candidate = str1[: candidate_len]
        # if candidate * (len(str1) // candidate_len) == str1 and candidate * (len(str2) // candidate_len) == str2:
        #     return candidate
        # return ''

        candidate_len = math.gcd(len(str1), len(str2))
        candidate = str1[:candidate_len]
        if str1 + str2 == str2 + str1:
            return candidate
        return ''

```