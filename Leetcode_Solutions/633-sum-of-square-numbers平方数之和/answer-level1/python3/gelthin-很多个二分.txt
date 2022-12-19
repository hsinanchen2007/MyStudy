### 解题思路
这一题方法，我的二分代码不好，更多方法参看官方题解。
假如不适用 sqrt 函数

python 的 sqrt 函数的效率不知道怎么样

+ 方法1 二分法：枚举 a, 同时搜索 b, 注意到要控制 b 的搜索范围
+ 方法2 双指针：但要注意控制范围，不然要超时了，用二分求出来 sqrt(c)
+ 方法3 数论方法： 4n+3 的因子都是偶数次幂



### 代码

```python3
class Solution:

    def my_binary_search(self, left, right, target):
        while left < right:
            mid = left + (right-left)//2
            if mid*mid < target:
                left = mid+1
            else:
                right = mid
        if left*left == target:
            return True, left
        elif left*left > target:
            return False, left
        else: # left*left < target 这个是不可能的
            return False, left+1

    def judgeSquareSum(self, c: int) -> bool:
        if (c == 0) or (c == 1):
            return True
        a = 0
        left, right = 0, c//2
        while a*a <= c:
            target = c - a*a
            if target == 0:
                return True
            flag, new_bound = self.my_binary_search(left, right, target)
            if flag == True:
                return True
            else:
                right = new_bound
                left = 0
                a += 1
        return False
```