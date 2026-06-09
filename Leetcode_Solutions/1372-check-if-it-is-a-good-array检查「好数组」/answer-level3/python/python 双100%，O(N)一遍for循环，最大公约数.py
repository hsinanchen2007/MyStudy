### 解题思路
这个题目返回false的充要条件是存在一个大于1的最大公约数A能够整除所有的数
求这个数的方式就是 先求头两个数的最大公约数,
然后拿这个公约数去求接下来那个数的最大公约数,
然后拿这个公约数去求接下来那个数的最大公约数,

如果存在A那么必定整个循环下来这个公约数得一直大于1...

### 代码

```python

# 求最大公约数
def get_common_divide(a, b):
    if b > a:
        a,b = b,a

    c = a % b
    res = b

    while c > 0:
        a, b = b, c
        res = c
        c = a % b
    return res


class Solution(object):
    def isGoodArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if 1 in nums:
            return True

        if len(nums) == 1:
            return False

        last = nums[0]
        for num in nums[1:]:
            v = get_common_divide(last, num)
            if v == 1:
                return True
            last = v
        return False
```