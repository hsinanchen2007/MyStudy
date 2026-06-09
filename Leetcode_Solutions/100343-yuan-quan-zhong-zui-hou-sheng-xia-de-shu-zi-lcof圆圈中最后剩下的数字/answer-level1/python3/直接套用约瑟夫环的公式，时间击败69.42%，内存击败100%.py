1. 直接模拟会超出限制
```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        nums = list(range(n))
        start = 0
        index = start+m-1
        for i in range(n-1):
            while index >= len(nums):
                index -= len(nums)
            print(index)
            print(nums)
            nums.pop(index)

            start = index
            index = start+m-1
        return nums[0]
```
2. 采用约瑟夫环的公式
f(n,m) = (f(n-1,m)+m)%3 就是获胜者的索引号
- 写法一
```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        if n == 0: return 0
        ans = (self.lastRemaining(n-1,m)+m) % n
        return ans
```
- 写法二
```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        f = 0
        for i in range(2,n+1):
            f = (f+m)%i
        return f
```
![QQ图片20200330143311.png](https://pic.leetcode-cn.com/7c4e7ae3c93c5c9126071aea328ea24b00868083f645c2329d1da7ede14fd4f0-QQ%E5%9B%BE%E7%89%8720200330143311.png)

