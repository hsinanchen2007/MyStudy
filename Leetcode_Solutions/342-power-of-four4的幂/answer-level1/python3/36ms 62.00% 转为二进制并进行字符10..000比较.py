### 解题思路
官方答案是用位运算处理的非常强，但是当时做的时候完全没想到...

这里的想法是将其转换为字符串，然后如果是4的幂次，二进制一定是10....00的形式且为奇数

### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        s = bin(num).replace('0b','')
        l = len(s)
        if s == ('1' + '0' * (l - 1)) and l % 2 == 1:
            return True
        else:
            return False

```