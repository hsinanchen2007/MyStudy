class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        # 最大的子序列不可能超过其中一个的长度，所以取最小
        min_len = min(len(str1), len(str2))
        # 倒序取字串的长度
        for i in range(min_len, 0, -1):
            # 确保字串的长度能够被两个字符串除尽
            if (len(str1) % i) == 0 and (len(str2) % i) == 0:
                # 判断全字符串是否能够由字串重复重组构成
                if str1[: i] * (len(str1) // i) == str1 and str1[: i] * (len(str2) // i) == str2:
                    return str1[: i]
        return ''