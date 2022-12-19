```python
class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        # Greedy
        # Time complexity  : O(A + B)
        # Space complexity : O(A + B)
        def process(A, B, ch1, ch2):
            # bbbb
            # aaa
            # => bb_bb => bbabb(rest = 3 - 1 = 2) => babaabb
            gap = (A - 1) // 2
            rest = B - gap
            res, new_res = '', ''
            for i in range(gap):
                res += 2 * ch1 + ch2
                A -= 2
            res += A * ch1
            for i in range(len(res)):
                new_res += res[i]
                if res[i] == ch1 and rest > 0:
                    new_res += ch2
                    rest -= 1
            return new_res

        if A > B: res = process(A, B, 'a', 'b')
        else: res = process(B, A, 'b', 'a')
        return res
```