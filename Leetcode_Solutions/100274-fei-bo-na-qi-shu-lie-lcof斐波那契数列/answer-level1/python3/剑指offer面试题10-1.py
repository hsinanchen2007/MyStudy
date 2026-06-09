# ### 解题思路
# 教科书上的递归代码居然超时了，👴怀疑人生了。。但是改了以下代码就不超时了，我感觉好像都差不多，不知道区别在哪里

# ### 代码

# ```python3
class Solution:
    def fib(self, n: int) -> int:
        if n <= 0:
            return 0
        elif n == 1:
            return 1
        else:
            a , b , i = 0 , 1 , 1
            while i < n:
                a, b = b, a + b
                i += 1
            return b % 1000000007
# ```