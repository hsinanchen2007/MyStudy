此题与上题相同，只需要将上题中的0替换为target，并将严格判定相等的条件替换为寻求最小值的条件即可。

整道题目的代码如下：

```python
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """

        nums.sort()
        minv = 1000

        for i in range(len(nums) - 2):
            num = target-nums[i]
            j = i + 1
            k = len(nums) - 1

            while j != k:
                sum = nums[j] + nums[k]
                if abs(sum - num) < minv:
                    minv = abs(sum - num)
                    res = sum + nums[i]
                if sum < num:
                    j = j + 1
                else:
                    k = k - 1

        return res
```

