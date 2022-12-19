### 解题思路
数学好也太帅了:3

### 代码

```python3
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # 如果 str1 和 str2 拼接后等于 str2和 str1 拼接起来的字符串（注意拼接顺序不同），那么一定存在符合条件的字符串 X。
        candidate_len = math.gcd(len(str1), len(str2))  # 获取到str1和str2长度的最大公约数
        candidate = str1[: candidate_len]
        if str1 + str2 == str2 + str1:
            return candidate
        return ''

        # for i in range(min(len(str1), len(str2)), 0, -1):
        #     if (len(str1) % i) == 0 and (len(str2) % i) == 0:
        #         if str1[: i] * (len(str1) // i) == str1 and str1[: i] * (len(str2) // i) == str2:
        #             return str1[: i]
        # return ''

# 作者：LeetCode-Solution

```