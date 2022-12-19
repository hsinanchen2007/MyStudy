'0'特殊处理
给s前面添加'9'可以简化处理

```py
class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """

        s = "9" + s
        length = len(s)

        dp_0, dp_1 = 1, 1
        for i in range(1, length):
            if s[i] == '0':
                if s[i-1] == '1' or s[i-1]== '2':
                    dp = dp_0
                else:
                    return 0
            else:
                if s[i-1] == '1' or (s[i-1] == '2' and '1' <= s[i] <= '6'):
                    dp = dp_0 + dp_1
                else:
                    dp = dp_1

            dp_0, dp_1 = dp_1, dp
        return dp_1
```

