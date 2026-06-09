### 解题思路
此处撰写解题思路
先排序，遍历列表中数字，对每个num左右加和，根据与target的大小比较，将左右索引顺序向列表两端移动。
时间复杂度为：n方
### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        res = sum(nums[:3])
        for i in range(1,len(nums)-1):
            pre_i, next_i = i-1, i+1
            while (pre_i>=0) and (next_i<=len(nums)-1):
                sum3 = nums[pre_i] + nums[i] + nums[next_i]
                if sum3==target:
                    return sum3
                elif sum3<target:
                    next_i += 1
                else:
                    pre_i -= 1
                if abs(res - target) > abs(sum3 - target):
                    res = sum3
        return res

```