### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def zhebanSearch(self,nums,begin,end,num2):
        low = begin
        high = end
        mid = (low + high) // 2

        while low <= high:
            mid = (low + high) // 2
            if nums[mid] == num2:
                return True,mid
            elif nums[mid] > num2:
                high = mid - 1
            else:
                low = mid + 1

        return False,mid

    def threeSum(self, nums):
        length = len(nums)
        if length < 3:
            return []
        res = []
        nums.sort()

        i = 0
        if nums[0] < 0 and nums[length-1] > 0:
            while nums[i] < 0:
                num1 = nums[i]

                position = i + 1
                j = length - 1
                while nums[j] > 0:
                    num3 = nums[j]
                    num2 = 0 - num1 - num3
                    if position > j - 1:
                        break
                    if num1 <= num2 and num2 <= num3:
                        found, position = self.zhebanSearch(nums, position, j - 1, num2)
                        if found:
                            res.append([num1, num2, num3])

                    # num3过滤
                    while nums[j] > 0 and num3 == nums[j]:
                        j -= 1
                # num1过滤
                while nums[i] < 0 and num1 == nums[i]:
                    i += 1

        if i+2 < length and nums[i] == 0 and nums[i+1] == 0 and nums[i+2] == 0:
            res.append([0,0,0])

        return res

```