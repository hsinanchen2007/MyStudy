```
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        # 4的幂肯定是大于0的
        # 第二个式子保证这个数是2的幂
        return num > 0 and num & (num - 1) == 0 and (num - 1) % 3 == 0
```

