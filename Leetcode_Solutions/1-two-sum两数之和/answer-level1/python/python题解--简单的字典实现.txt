![image.png](https://pic.leetcode-cn.com/8f3af7149c109f71d6a1e799351fd463fde6203bf884f0fbec722290c9483bf8-image.png)

- 这里只提供下代码,思路很简单~~,只需用字典存储,用空间换时间
- 时间复杂度`O(n)`,空间复杂度`O(n)`
### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dic = {}
        for i in range(len(nums)):
            if (target - nums[i]) in dic:
                return [i,dic[target-nums[i]]]
            dic[nums[i]] = i 

```