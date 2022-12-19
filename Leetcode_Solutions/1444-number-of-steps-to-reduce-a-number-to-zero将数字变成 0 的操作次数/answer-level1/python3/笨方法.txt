### 解题思路
考虑到不管是奇数还是偶数，最后一步操作一定是减1操作，那么只需要判断num是否为1即可，在num不为1的情况下，执行循环，判断奇偶性，并进行相关操作。

### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        count = 0
        while num != 1:
            if num % 2 == 0:
                num /= 2
                count += 1
            else:
                num -= 1
                count += 1
        count += 1
        return count
```