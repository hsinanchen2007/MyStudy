### 解题思路
1、负数一定不是回文数
2、创建一个数字为输入的逆序
3、判断逆序与正序是否相等

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        reversX = 0
        y = x
        while x > 0:
            reversX = reversX * 10 + x % 10
            x = x // 10
            print(reversX)
            print(x)
        if reversX == y:
            return True
        else:
            return False
```