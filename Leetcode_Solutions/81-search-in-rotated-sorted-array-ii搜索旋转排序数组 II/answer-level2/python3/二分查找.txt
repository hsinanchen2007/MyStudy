执行用时 :52 ms, 在所有Python3提交中击败了91.12% 的用户。
内存消耗 :13.1 MB, 在所有Python3提交中击败了99.56%的用户。

思路1，直接`return target in nums`

思路2，二分查找，首先找到旋转点，将数组分为两部分，再判断target可能处于哪个数组，再进行二分查找。

```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if not nums:
            return False
        n = len(nums)
        if n == 1:
            return nums[0] == target
        flag = n - 1
        for i in range(1, n):
            if nums[i] < nums[i-1]:
                flag = i - 1
                break
        if target == nums[0]:#判断target可能存在的数组
            return True
        elif target > nums[0]:
            l, r = 0, flag
        else:
            l, r = flag + 1, n -1
        while l <= r:
            mid = (l+r)//2
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return False
```