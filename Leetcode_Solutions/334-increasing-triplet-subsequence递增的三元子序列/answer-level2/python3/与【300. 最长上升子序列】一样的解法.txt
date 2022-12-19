该题与[300. 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/)方法一致，只不过本题动态维护的递增数组长度最大为3，每次比较的最大次数为3。
```
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:return False
        record = [nums[0]]

        for i in range(1,len(nums)):
            if nums[i] > record[-1]:
                record.append(nums[i])
                if len(record) == 3:return True
            elif nums[i] < record[-1]:
                for j in range(len(record)):
                    if nums[i] <= record[j]:
                        record[j] = nums[i]
                        break

        return False
```
时间复杂度:因为维护的数组长度有限，每次的**最大比较次数为3**，所以时间复杂度为$O(n)$
空间复杂度:维护数组的**最大长度为3**，所以空间复杂度为$O(1)$