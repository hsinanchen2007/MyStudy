# 精心汇总python3的5种实现方法

"""
解题思路: (五种实现方法)
    1. 转成字符串:
        a. 双向队列
        b. 双指针
    2. 不转字符串:
        a. 模拟字符串的双向队列(使用math库的log函数 获取整数的位数)
        b. 反转后面一半的整数(使用math库的log函数 获取整数的位数)
        c. 反转后面一半的整数(不适用log函数) (通过原整数x 与 reverse_x 的大小判断)
"""

```python3
class Solution:

    # 方法一: 将int转化成str类型: 双向队列
    # 复杂度: O(n^2) [每次pop(0)都是O(n)..比较费时]
    def isPalindrome(x: int) -> bool:
        lst = list(str(x))
        while len(lst) > 1:
            if lst.pop(0) != lst.pop():
                return  False
        return True


    # 方法二: 将int转化成str类型: 双指针 (指针的性能一直都挺高的)
    # 复杂度: O(n)
    def isPalindrome(x: int) -> bool:
        lst = list(str(x))
        L, R = 0, len(lst)-1
        while L <= R:
            if lst[L] != lst[R]:
                return  False
            L += 1
            R -= 1
        return True


    # 方法三: 进阶:不将整数转为字符串来解决: 使用log来计算x的位数
    # 复杂度: O(n)
    def isPalindrome(self, x: int) -> bool:
        """
        模仿上面字符串的方法:分别取'第一位的数'与'第二位的数'对比
                        (弊端是:频繁计算,导致速度变慢)(下面的方法三只反转一半数字,可以提高性能)
        """
        if x < 0:
            return False
        elif x == 0:
            return True
        else:
            import math
            length = int(math.log(x, 10)) + 1
            L = length-1
            print("l = ", L)
            for i in range(length//2):
                if x // 10**L != x % 10:
                    return False
                x = (x % 10**L) //10
                L -= 2
            return True

    # 方法四: 进阶:不将整数转为字符串来解决: 使用log来计算x的位数
    # 复杂度: O(n)
    def isPalindrome(self, x: int) -> bool:
        """
        只反转后面一半的数字!!(节省一半的时间)
        """
        if x < 0 or (x!=0 and x%10==0):
            return False
        elif x == 0:
            return True
        else:
            import math
            length = int(math.log(x, 10)) + 1
            reverse_x = 0
            for i in range(length//2):
                remainder = x % 10
                x = x // 10
                reverse_x = reverse_x * 10 + remainder
            # 当x为奇数时, 只要满足 reverse_x == x//10 即可
            if reverse_x == x or reverse_x == x//10:
                return True
            else:
                return False

    # 方法五: 进阶:不将整数转为字符串来解决: 不使用log函数
    # 复杂度: O(n)
    def isPalindrome(self, x: int) -> bool:
        """
        只反转后面一半的数字!!(节省一半的时间)
        """
        if x < 0 or (x!=0 and x%10==0):
            return False
        elif x == 0:
            return True
        else:
            reverse_x = 0
            while x > reverse_x:
                remainder = x % 10
                reverse_x = reverse_x * 10 + remainder
                x = x // 10
            # 当x为奇数时, 只要满足 reverse_x//10 == x 即可
            if reverse_x == x or reverse_x//10 == x:
                return True
            else:
                return False





x = 10
x = 10001
print(Solution().isPalindrome(x))

```