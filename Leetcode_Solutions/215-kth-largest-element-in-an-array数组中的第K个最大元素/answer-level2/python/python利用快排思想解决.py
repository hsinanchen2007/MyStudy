### 解题思路
快排每次可以确定一个元素在排序中的最终位置，因此可利用这一点，每次确定下来一个位置，就检查是不是就是第k个，若是直接返回，程序结束。若不是，则根据确定下来的位置是k的前还是后，相应的在前半段或者后半段继续寻找第k个

### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if not nums or not k:
            return None
        high = len(nums)-1
        if k-1 > high:
            return None
        low = 0
        while low <= high:
            ind = self.partition(nums,low,high)
            if ind == k - 1:
                return nums[ind]
            elif ind > k - 1:
                high = ind - 1
            else:
                low = ind + 1
        return None

    def partition(self,nums,low,high):
        val = nums[high]
        p = low
        for i in range(low,high):
            if nums[i] >= val:
                nums[p],nums[i] = nums[i],nums[p]
                p += 1
        nums[p],nums[high] = nums[high],nums[p]
        return p
        

```