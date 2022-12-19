### 解题思路
找出给定数组的最大值，然后找出1到该最大值加1（解决nums中包含max（nums）中所有值得情况）中不属于nums的值返回就行
![image.png](https://pic.leetcode-cn.com/0962bfc62c60e05833240f393e983d5f791c8296513af72cfe8cce4a7e053a2b-image.png)

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        if not nums:
            return 1
        if max(nums) < 1:
            return 1
        for i in range(1,max(nums)+2):
            if i not in nums:
                return i



```