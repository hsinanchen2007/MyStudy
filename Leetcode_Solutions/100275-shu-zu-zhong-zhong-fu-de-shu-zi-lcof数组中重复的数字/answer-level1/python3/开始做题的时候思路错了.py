### 解题思路
开始做的时候以为是要找出所有的重复的数字，结果只需要找到一个就好
那就对数组排序然后找到第一个重复的数字return就好

### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        nums.sort()
        if not nums:
            return 0
        if len(nums)==1:
            return nums[0]
        temp=nums[0]
        for i in nums[1:]:
            if i==temp:
                return i
            else:
                temp=i
```![image.png](https://pic.leetcode-cn.com/7b3bf77fd3ecdac6894334eebbc97dbeae1f814f4dd11dc53dc72a33a5bf9768-image.png)
