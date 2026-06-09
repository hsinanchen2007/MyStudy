```
# https://leetcode-cn.com/problems/string-without-aaa-or-bbb/
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        if A <= 2 and B <= 2:
            return 'a' * A + 'b' * B
        if A >= B:
            main_letter = 'a'
            minor_letter = 'b'
            main_count = A
            minor_count = B
        else:
            main_letter = 'b'
            minor_letter = 'a'
            main_count = B
            minor_count = A
        seg_count = main_count + 1 if main_count % 2 else main_count
        res = [''] * seg_count
        for i in range(0, seg_count - 2, 2):
            res[i] = main_letter * 2
        res[-2] = main_letter if main_count % 2 else main_letter * 2
        minor_surplus = minor_count - (seg_count >> 1) + 1
        for i in range(1, seg_count - 2, 2):
            res[i] = minor_letter * 2 if minor_surplus else minor_letter
            minor_surplus -= 1 if minor_surplus else 0
        res[-1] = minor_letter * minor_surplus
        res_str = ''
        for i in res:
            res_str += i
        return res_str

```
