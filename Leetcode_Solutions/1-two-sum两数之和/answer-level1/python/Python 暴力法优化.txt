### 解题思路
相比于两循环暴力法，我这个方法少走了一半的循环，虽不如字典的快。
由于仅求两数之和，所以从第二个数开始，只有加前面的数字就可以了。

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(1,len(nums)):
            for j in range(i):
                if nums[i]+nums[j] == target:
                    return [j,i]
```