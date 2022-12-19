### 解题思路
通过转换成str格式，再用len函数获取字符串个数，该个数就是位数；用该位数%2若为0即为偶数，通过定义一个变量每次+1即可得到位数为偶数的数字的个数

### 代码

```python3
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        a = 0
        for i in range(0,len(nums)):
            n = len(str(nums[i]))
            m = n % 2
            if m == 0:
                a+=1
            i += 1
        return a
```