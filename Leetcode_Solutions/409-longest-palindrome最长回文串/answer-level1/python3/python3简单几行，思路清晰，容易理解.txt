# 思路
最终回文串应该是s中全部偶数个数字符参与，全部奇数个数字符去掉一个编程偶数个字符参与，且可以保留一个奇数个数字符

即，至多一个奇数个数字符参与回文串

res = len(s) - 奇数字符的个数 + 1

如果s中全部为偶数个数的字符，则

res = len(s)

# python3代码
```python3
class Solution:
    def longestPalindrome(self, s: str) -> int:
        cnt_odd = 0
        # 统计奇数的个数
        for _ in set(s):
            if s.count(_) & 1 == 1:
                cnt_odd += 1
        # result=s总长度 - 奇数个数 + 1，
        # 但是奇数个数可能为0，此时不能减1
        return len(s) - max(cnt_odd, 1) + 1
```