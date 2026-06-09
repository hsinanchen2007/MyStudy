说一下思路，
![image.png](https://pic.leetcode-cn.com/32230400169676b041d1661413b8ca549eb63757f74fd0772da4e43f4f5addfc-image.png)
 (1) 中找出最大的索引 k 满足 nums[k] < nums[k+1]； 因存在nums[k] < nums[k+1]，该式必然可以通过调换元素提高整个式子的值；而最大索引是为了让整个式子提升值最小是在k位置进行变化（在哪里：k）；
（2）再找出另一个最大索引 l 满足 nums[l] > nums[k]，因k是 满足 nums[k] < nums[k+1]最大的索引，k后单调递减，最大索引 l其实意味最小值，也是为了让整个式子在k位提升值最小 （k应该变多少）；
（3）[k+1:]重排，得到k位后所有位的最小组合（余下式子最优）。

有一点像minmax的思想。

```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        first_index = -1
        for i in range(len(nums)-1, -1, -1):
            if nums[i] > nums[i-1] :
                first_index = i-1
                break
        if first_index == -1:
            nums.reverse()
            return

        sec_index = first_index
        for j in range(first_index+1, len(nums)):
            if nums[j] > nums[first_index] and j > sec_index:
                sec_index = j
        temp = nums[sec_index]
        nums[sec_index] = nums[first_index]
        nums[first_index] = temp
        nums[first_index+1:] = sorted( nums[first_index+1:])
        return
```
