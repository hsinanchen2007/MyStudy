```
class Solution:
    def longestPalindrome(self, s: str) -> int:
        List = []
        flag = 0
        index = 0
        for s_s in set(s):
            # 偶数次的字符前后插入List
            if s.count(s_s) % 2 == 0:
                for i in range(s.count(s_s) // 2):
                    List.append(s_s)
                    List.insert(0, s_s)
            # 大于1的奇数次字符可以拆解1+偶数次字符，加入偶数次字符放入List
            elif s.count(s_s) > 1:
                for x in range(s.count(s_s) - 1):
                    List.insert(len(List) // 2, s_s)
                    flag = 1 # 标记大于1的奇数次字符留一个作为回文数中心位
                    index = 0 # 去除只出现过一次的奇数作为中心位
            elif index == 0:
                index = 1
                flag = 0

        return len(List) + flag + index
```

题解：
    1.最初考虑问题只想到了，只要是偶数次得字符全部加入最后len中，奇数次的字符取最大长度加入最后len中
    2.这里忽略了一个问题，大于1的奇数是可以组成1+偶数形式的，这里的偶数次其实也是可以放入最后len中组成回文数长度的
总结：
    暴力就是蠢
    