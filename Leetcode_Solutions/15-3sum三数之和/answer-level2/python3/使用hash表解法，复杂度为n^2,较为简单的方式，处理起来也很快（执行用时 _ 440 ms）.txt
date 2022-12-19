### 解题思路
参照之前各位大佬的解法，简单说一下自己的思路（参照了之前的双指针的思路做了优化）
1、先排序
2、特殊情况处理一下（长度小于3，全为正数，全为负数，全为0）
3、将所有值存入hash表
4、做两次循环判定

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums_length = len(nums)
        if nums_length < 3:
            return []
        nums.sort()
        #全是正数或者全是负数，无解
        if nums[0] > 0 or nums[nums_length - 1] < 0:
            return []
        #全是0的情况处理，无需循环
        if nums[0] == 0 and nums[nums_length - 1] == 0:
            return [[0, 0, 0]]
        result = []
        #hash字典存储数据
        target_dic = {x: i for i, x in enumerate(nums)}
        temp_row = None
        for i, first in enumerate(nums):
            if i < nums_length - 1 and first + nums[i + 1] > 0:
                break
            if i > 0 and nums[i - 1] == first:
                continue
            for j, second in enumerate(nums[i + 1:]):
                target = -(first + second)
                if target in target_dic:
                    target_index = target_dic[target]
                    #这个判断用来判定这个值在first和second的后面，避免重复取值
                    if target_index > i + j + 1:
                        target_row = [first, second, target]
                        #已经有序的情况下，只需判定是否等于上一个值即可去重
                        if target_row != temp_row:
                            result.append(target_row)
                            temp_row = target_row
        return result
```