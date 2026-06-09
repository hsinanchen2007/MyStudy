## 思路：

这道题难点，在于如何解决循环重复的情况？

备注：我这里都是用字符串求和，也可以用数学方法（取余那种）

方法一：用哈希记录

```python
class Solution:
    def isHappy(self, n: int) -> bool:
        n = str(n)
        visited = set()
        while 1:
            n = str(sum(int(i) ** 2 for i in n))
            if n == "1":
                return True
            if n in visited:
                return False
            visited.add(n)
```

方法二：快慢（跑）

```python
class Solution:
    def isHappy(self, n: int) -> bool:
        n = str(n)
        slow = n
        fast = str(sum(int(i) ** 2 for i in n))
        while slow != fast:
            slow = str(sum(int(i) ** 2 for i in slow))
            fast = str(sum(int(i) ** 2 for i in fast))
            fast = str(sum(int(i) ** 2 for i in fast))
        return slow == "1"
```