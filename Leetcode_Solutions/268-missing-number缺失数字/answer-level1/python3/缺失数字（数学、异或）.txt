### 解题思路-数学
缺失的数字=sum([0,...,n])-sum(nums)；其中可以通过数学公式计算sum([0,...,n]);

时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        length = len(nums)
        if length == 0:
            return 0
        
        sum_total = length*(length+1)/2
        sum_lack = sum(nums)

        return int(sum_total-sum_lack)
```

### 解题思路-异或
将[0,...,n]中所有整数的异或结果与nums中的所有整数异或；所得的值即为缺失值；

因为nums中的所有整数在[0,...,n]中都出现过一次，而缺失的数字只有在[0,...,n]中出现一次，因此这些整数的异或结果即为只出现一次的缺失数字；

时间复杂度：O(n)
空间复杂度：O(1)

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        # length和nums中的所有下标i即为[0,...,n]
        length = len(nums)
        for i,num in enumerate(nums):
            length ^= i^num

        return length
```