### 解题思路
按照书上的写法，是将原本的数组当成哈希表了，时间复杂度O(n),空间复杂度O(1)。看了讨论区发现，这题需要提前跟面试官沟通所需要的时间空间，是否能修改原数组。
如果要求时间复杂度为O(n)，空间不限制，那么直接用字典就可以。如果还限制空间复杂度O(1)，那么就要原地修改数组。如果不能修改数组，看题解似乎还有二分解法。

### 代码

```python3 
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        n=len(nums)
        for i in range(n):
            index=nums[i] % n if nums[i]>=n else nums[i] # 先把这个数字本身还原出来
            if nums[index]>=n:
                return index
            else:
                nums[index]+=n

```