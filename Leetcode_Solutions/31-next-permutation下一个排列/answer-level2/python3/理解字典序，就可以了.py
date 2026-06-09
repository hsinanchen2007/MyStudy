### 解题思路
1.从右至左遍历·`nums`，发现第一个小于右边的数`nums[i]`，将该`nums[i]`之后的数排升序；2.第二层遍历`nums[(i+1):]`，发现第一个大于`nums[i]`的数`nums[j]`，交换两数，退出遍历break；3.交换了也排好序了，退出第一次层遍历return `nums`

这里有个细节：`nums`本来就是降序，第一次遍历找不到`nums[i]`,那么直接`sort()`

### 代码

```python3
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        for i in range(n - 2, -1, -1):
            if nums[i] < nums[i + 1]:
                nums[(i + 1):] = sorted(nums[(i + 1):])
                for j in range(i + 1, n):
                    if nums[i] < nums[j]: 
                        nums[i], nums[j] = nums[j], nums[i]
                        
                        break
                return nums
        nums.sort()
```
执行用时 :40 ms, 在所有 Python3 提交中击败了79.66%的用户
内存消耗 :13.4 MB, 在所有 Python3 提交中击败了5.01%的用户