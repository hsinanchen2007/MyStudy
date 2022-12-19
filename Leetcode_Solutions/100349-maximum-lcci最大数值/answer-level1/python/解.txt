```
class Solution:
    def maximum(self, a: int, b: int) -> int:
        sign_a = (a & 0xffffffff) >> 31
        sign_b = (b & 0xffffffff) >> 31
        sign_diff = ((a-b) & 0xffffffff) >> 31

        #不同取a的符号
        temp_a = sign_a ^ sign_b
        #相同取差的符号
        temp_diff = sign_a ^ sign_b ^ 1

        flag = temp_a * sign_a + temp_diff * sign_diff

        return b * flag + a * (flag ^ 1)
```
