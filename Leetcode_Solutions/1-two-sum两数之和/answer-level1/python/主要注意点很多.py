### 解题思路
此处撰写解题思路
负数，时间限制（很大的数组），相等数
最开始用暴力破解两次遍历，加个targe大于0的判断，测试案例中有负数不行...
看下其他人思路，一层遍历，判断结果是否在数组中，存在则返回。
照着做了，发现数字重复索引，加个异常，太多东西没注意到...
### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = []
        for i in range(len(nums)):
            if (target - nums[i]) in nums:
                try:
                    result.append(i)
                    result.append(nums.index(target - nums[i], i+1))
                except Exception as e:
                    result.clear()
                else:
                    return result
        return result
```