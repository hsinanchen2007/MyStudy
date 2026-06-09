### 解题思路
1.判断边界条件
2.进入for循环，从头开始查找
3.i=0,判断nums[nums[i]] == nums[i],不相等就互换位置，把nums[0]的值  换到 nums[nums[0]]上面去。
4.i=0  此时nums[0]为换完位置后的值。继续判断

5.如果i=0 不需要互换，i = 1继续

### 代码

```python3
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        if len(nums) <= 1:
            return False
        for i in range(len(nums)): 
            while i != nums[i]:                                                     
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                else:
                    nums[nums[i]],nums[i] = nums[i],nums[nums[i]]
                    #print(nums)
        