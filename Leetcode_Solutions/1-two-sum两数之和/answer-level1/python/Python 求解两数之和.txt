这一题也介绍两种方法。
### 方法一：
第一种是大家最熟悉的暴力法，两层循环遍历，即可得出答案。

代码如下：
```python
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_length = len(nums)
        for one_num in range(nums_length-1):
            for second_num in range(one_num+1, nums_length):
                if nums[one_num] + nums[second_num] == target:
                        return [one_num, second_num]
                    
                    
if __name__ == '__main__':
    nums = [2, 7, 11, 15]
    target = 9
    solution = Solution()
    result = solution.twoSum(nums, target)
    print(result)
```

执行效率那自然是不用说了，差的不能再差了，差点要超出时间限制了。

### 方法二：

此方法在方法一的基础上改进了，只需要一层循环即可找出答案。即根据当前遍历得到的元素index，查找target-index是否在剩余数组里出现，如果找得到，则返回其下标值；反之则说明没有该答案。

代码如下：

```python
class Solution(object):
    # 可用一遍遍历，即根据当前遍历得到的元素index，
    # 查找target-index是否在剩余数组里出现
    # 如果找得到，则返回其下标值；反之则说明没有该答案
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        answer = []
        for left_index in range(len(nums)):
            right = target - nums[left_index]
            if right in nums[left_index+1:]:
                nums_right = nums[left_index+1:]
                right_index = nums_right.index(right)+left_index+1
                answer.extend([left_index, right_index])
                break
        return answer


if __name__ == "__main__":
    nums = [-1, -2, -3, -4, -5]
    target = -8
    answer = Solution().twoSum(nums, target)
    print(answer)
```
执行效率还算不错，在 60% 左右。