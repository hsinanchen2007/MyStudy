### 解题思路
考虑特殊情况，负数，10的倍数直接返回False
仅反转后一半的数，并与前一半比较是否相同。
存在一种情况121，后一半的数为12，前一半为1，所以也需要比较x是否与num_r//10相同。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 or (x % 10 == 0 and x !=0) :
            return False
        num_r = 0
        while x > num_r:
            num_r = num_r * 10 + x % 10
            x //= 10
        return (x == num_r or x == num_r//10)

```