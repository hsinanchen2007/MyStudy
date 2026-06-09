很容易可以发现下面规律：

# fn(3) = 1 * fn(2) + 1 * fn(1)
# fn(4) = 2 * fn(2) + 1 * fn(1)
# fn(5) = 3 * fn(2) + 2 * fn(1)
# fn(6) = 5 * fn(2) + 3 * fn(1)
# fn(7) = 8 * fn(2) + 5 * fn(1)
# 发现规律，函数的参数正是菲波那切数列
还要记得菲波那切数列要用循环来实现，而不要用递归的方式，递归的方式来实现太消耗时间和空间，提交是通不过的。

下面是代码的实现：
```

class Solution:

    # 递归实现太消耗时间与空间了，改成循环的方式
    # def fn(self, n):
    #     if n == 3 or n == 4:
    #         return 1
    #     else:
    #         return self.fn(n - 1) + self.fn(n - 2)
    # 采用循环的方式来实现
    def fn(self, n):
        if n == 3 or n == 4:
            return 1
        x, y = 1, 1
        for i in range(5, n + 1):
            myfib = x + y
            x = y
            y = myfib
        return myfib

    def getargs(self, n):
        return self.fn(n + 1), self.fn(n)

    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        elif n == 2:
            return 2
        else:
            a, b = self.getargs(n)
            return 2 * a + b
```

