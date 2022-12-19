**一：暴力法**
两层循环暴力检索，不能AC。时间O(n*n)，空间O(1)
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return []
```
**二：夹逼法**
考虑排序+夹逼降低时间复杂度的可能性，类似一种贪心的思路。排序后首尾之和>target,则尾部前移，首尾之和<target,则头部后移，直至问题求解。
由于排序会丢失原始下标，需要存储，时间O(n*logn),空间O(n)
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        //构造带原始下标的元组后排序
        pairNums = []
        for i in range(len(nums)):
            pairNums.append((nums[i], i))
        pairNums = sorted(pairNums, key = lambda x:x[0], reverse=False)

        //前后夹逼
        start, end = 0, len(pairNums) - 1
        while start < end:
            if pairNums[start][0] + pairNums[end][0] > target:
                end -= 1
            elif pairNums[start][0] + pairNums[end][0] < target:
                start += 1
            else:
                ret = [pairNums[start][1], pairNums[end][1]]
                ret.sort()
                return ret
        return []
```
**三：字典查找**
如果仍然要找到更有性能的解法，回到问题的原点：求两数之和=target，也就是固定数组一个元素n的同时，搜索剩余元素中是否存在target-n，字典可破：一边遍历，一边查找数差或插入该数。时间O(n),空间O(n)
```
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numDict = {}
        for index in range(0, len(nums)):
            if target - nums[index] in numDict:
                return [numDict[target - nums[index]], index]
            else:
                numDict[nums[index]] = index
        return []
```


