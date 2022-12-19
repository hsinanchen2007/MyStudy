此题与第十五题相同，此不赘述。

整道题目的代码如下：

```python
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = set()
        nums.sort()
        length = len(nums)

        for i in range(len(nums) - 3):
            for j in range(i+1, len(nums) - 2):
                t = target - nums[i] - nums[j]
                k = j + 1
                l = length - 1
                while(k != l):
                    sum = nums[k] + nums[l]
                    if sum == t:
                        res.add((nums[i], nums[j], nums[k], nums[l]))
                        k = k + 1
                    elif sum < t:
                        k = k + 1
                    else:
                        l = l - 1

        return list(res)
```

