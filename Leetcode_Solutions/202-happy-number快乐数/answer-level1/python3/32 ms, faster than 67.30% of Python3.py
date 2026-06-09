### 解题思路
快慢指针还能这样用!!!
判断循环就用快慢指针!

一开始的思路是记录init=n, 然后如果之后计算结果出现n的话代表进入死循环
方向是对的, 但是应该记录所有的中间结果而不是只记录init. 用set去记录
但是这样可能会导致set过大, 而且空间复杂度不是O(1), 还是用快慢指针

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        def solve(n):
            tmp = 0
            while n:
                tmp += (n%10)**2
                n //= 10
            return tmp
        
        fast = slow = n
        while True:
            slow = solve(slow)
            fast = solve(solve(fast))
            if slow==fast:
                break
        return slow==1
```