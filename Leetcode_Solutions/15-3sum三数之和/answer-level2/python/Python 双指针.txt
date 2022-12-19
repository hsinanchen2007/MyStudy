本题其实是两个元素的和等于0的升级版：本质上还是双指针的应用
用一个指针指向当前元素，设为x： 实际上就是在后面数组中找到两个元素的和等于-x；
但本题有一个重复元素处理的问题需要注意，代码如下：
```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 这个子函数用来解决2sum = targetSum问题
        def getPair(left, targetSum):
            leftTemp, rightTemp = left, right
            while leftTemp < rightTemp:
                curSum = nums[leftTemp] + nums[rightTemp]
                if curSum > targetSum:
                    rightTemp -= 1
                elif curSum < targetSum:
                    leftTemp  += 1
                else:
                    triplets.append([-targetSum, nums[leftTemp], nums[rightTemp]])
                    # 满足条件 则左右指针同时进一步，因为不会有比他们大/小的元素满足要求了（数组已排序）
                    rightTemp -= 1
                    leftTemp  += 1
                    # 但只前进一步还不够，可能会指向重复元素，而题目要求去重->跳过重复元素，避免完全一致的triplet
                    while leftTemp < rightTemp and nums[rightTemp] == nums[rightTemp + 1]:
                        rightTemp -= 1
                    while leftTemp < rightTemp and nums[leftTemp] == nums[leftTemp - 1] :
                        leftTemp += 1
        triplets = []
        right = len(nums) - 1
        nums.sort()
        for i in range(len(nums)):
            # 去重
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            getPair(i + 1, -nums[i])
        return triplets

```
排序的算法复杂度是O(nlogn)
getPair()调用n次，总复杂度是O(n^2)
综上算法复杂度为O(n^2)