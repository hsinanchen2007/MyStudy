### 解题思路
回文数：头尾比较
x = [1 2 3 4]
x[-1]    #4 取最后一个元素
x[:-1]   #1 2 3 取 ‘除了最后一个元素’ 的其他元素
x[::-1]  #4 3 2 1 从后往前取元素
x[2::-1] #3 2 1 从下标为2的元素往前取

### 代码

```python3
#法一
class Solution:
    def isPalindrome(self, x):
        self.x = x
        l = list(str(x))
        H = 0
        T = len(l) - 1
        while T > H:
            if l[H] != l[T]:
                return False
            else:
                H += 1
                T -= 1
        return True #88ms

#法二
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if str(x)==str(x)[::-1]:
            return True
        else: 
            return False  #76ms


s = Solution()
s.isPalindrome(1121)