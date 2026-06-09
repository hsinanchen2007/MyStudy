### 解题思路
找到最后一段升序的最后一个值，如有一段序列，a<b<c>d>e,其中d>b,e<b,则先取b,再在从c开始的降序中找到比b大的最小的值，即d，交换b与d，并将b以后的序列从小到大排序即为所求。

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        t = 0
        for i in range(len(nums) - 1, 0, -1):
            if nums[i] > nums[i - 1]:
                t = i
                break
        s = len(nums) - 1
        if t > 0:
            for i in range(t, len(nums)):
                if nums[i] <= nums[t - 1]:
                    s = i - 1
                    break
            temp = nums[s]
            nums[s] = nums[t - 1]
            nums[t - 1] = temp
            nums[t:len(nums)] = sorted(nums[t:len(nums)])
        else:
            nums[::] = nums[::-1]



```