### 解题思路
简单解法翻转字符串，返回字串符 64ms12.7mb

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        return str(x)[::-1] == str(x)
```
### 解题思路
log10 (x+0.1)排除x为0报错，转化列表法
%10，取个位
```
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = [int(x*10**-i%10) for i in range(int(math.log10(x+0.1)),-1,-1)] if x >= 0 else [1,2]
        return x == x[::-1]
```

