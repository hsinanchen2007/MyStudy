### 解题思路
我把java的快慢指针的方法改了一个python的版本。
执行用时 :
32 ms, 在所有 Python3 提交中击败了93.19%的用户
内存消耗 :
13.3 MB, 在所有 Python3 提交中击败了5.28%
的用户

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        start_p = self.get_next(n)
        end_p = self.get_next(start_p)
        if end_p == 1:
            return True
        while start_p != end_p:
            start_p = self.get_next(start_p)
            end_p = self.get_next(self.get_next(end_p))
            if end_p == 1:
                return True
        return False

    def get_next(self, n):
        result = 0
        while n:
            result += (n % 10) ** 2
            n = n//10
        return result



```