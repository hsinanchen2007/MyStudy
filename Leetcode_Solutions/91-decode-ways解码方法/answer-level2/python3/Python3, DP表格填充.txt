1. res用来动态记录s中每个字符的解码方法总数，res[0]用来解决s[0]的问题
2. 当计算s[i]的解码方法总数时，需要考虑s[i-1:i+1]即当前位置和上一个位置组成的数字中是否包含零
    不包含零时需要考虑s[i-1:i+1]是否在[1, 26]的区间之内
    包含零时分三种情况：
        如果组合数是两个零，证明无解
        如果s[i-1]为零，则s[i]的解码方法总数即为s[i-1]的解码方法总数
        如果s[i]为零，则需考虑s[i-1:i+1]是否在[1, 26]的区间之内, 如果在则s[i]的解码方法总数为s[i-1]的解码方法总数
      
```
class Solution:
    def numDecodings(self, s: str) -> int:
        """
            解码方法(非最优解)

            一条包含字母 A-Z 的消息通过以下方式进行了编码：
            'A' -> 1
            'B' -> 2
            ...
            'Z' -> 26
            给定一个只包含数字的非空字符串，请计算解码方法的总数。
            输入: "226"
            输出: 3
            解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
        """
        res = [1] + [0] * len(s)
        if not s:
            return 0
        for i in range(0, len(s)):
            if i == 0:
                if s[i] == "0":
                    return 0
                else:
                    res[i + 1] += res[i]
            elif s[i - 1] != "0" and s[i] != "0":
                if 0 < int(s[i - 1:i + 1]) < 27:
                    res[i + 1] += res[i] + res[i - 1]
                else:
                    res[i + 1] += res[i]
            elif s[i - 1] == "0" and s[i] == "0":
                return 0
            elif s[i - 1] == "0":
                res[i + 1] += res[i]
            elif s[i] == "0" and 0 < int(s[i - 1:i + 1]) < 27:
                res[i + 1] += res[i - 1]

        return res[-1]
```