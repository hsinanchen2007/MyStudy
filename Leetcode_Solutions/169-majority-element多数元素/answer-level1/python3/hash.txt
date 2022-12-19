### 解题思路
左右两边同时开始向中间走
估计用双线程或者双指针的方式会走得更快一点

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        size = len(nums)
        if size == 1:
            return nums[0]
        i, j = 0, size -1
        # 左右两边同时开始向中间走
        # 终止条件： 某个数的value > size/2
        x = dict()
        while 1:
            if nums[i] in x.keys():
                x[nums[i]] += 1
                if x[nums[i]] > size/2:
                    return nums[i]
                else:
                    i += 1
            else:
                x[nums[i]] = 1
                i += 1

            '''if nums[j] in x.keys():
                x[nums[j]] += 1
                j -= 1'''
             


```