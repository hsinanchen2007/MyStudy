```javascript []
console.log('Hello world!')
```
```python []
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        result = []
        nums = sorted(nums)
       
        for i in range(0, len(nums)-2):
            if nums[i] > 0:
                return result

            if i == 0 or nums[i] != nums[i-1]:
                
                L, R = i+1, len(nums)-1
                while L<R:
                    temp = nums[i]+nums[L]+nums[R]
                    if temp == 0:
                        if nums[L+1] == nums[L] and L+1 != R:
                            L += 1
                        elif nums[R-1] == nums[R] and R-1 != L:
                            R -= 1
                        else:
                            result.append([nums[i], nums[L], nums[R]])
                            L, R = L+1, R-1
                    elif temp > 0:
                        R -= 1
                    elif temp < 0:
                        L += 1

        return result

# 首先对数组进行排序，排序后固定一个数 nums[i]，再使用左右指针指向 nums[i]后面的两端，数字分别为 nums[L]和 nums[R]，计算三个数的和 sum 判断是否满足为 0，满足则添加进结果集
# 如果 nums[i]大于 0，则三数之和必然无法等于 0，结束循环
# 如果 nums[i] == nums[i−1]，则说明该数字重复，会导致结果重复，所以应该跳过
# 当 sum == 0 时，nums[L] == nums[L+1] 则会导致结果重复，应该跳过，L++
# 当 sum == 0 时，nums[R] == nums[R−1] 则会导致结果重复，应该跳过，R−−
```
```ruby []
puts 'Hello world!'
```
