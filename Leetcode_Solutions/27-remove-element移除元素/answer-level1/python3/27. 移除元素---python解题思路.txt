由于做[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)的时候没认真看题目有了教训后，这次我就非常认真的看了一下题目，发现和26其实大同小异[删除排序数组中的重复项---python解题思路](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-p-3/)

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        # 如果要移出的元素不在里面就不进行处理
        if val not in nums: return len(nums)
        replace = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[replace] = nums[i]
                replace += 1
        return replace
```

运行结果

```
执行用时 :36 ms, 在所有 python3 提交中击败了94.30% 的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.31%的用户

执行用时 :36 ms, 在所有 python3 提交中击败了94.30% 的用户
内存消耗 :12.8 MB, 在所有 python3 提交中击败了99.31%的用户

执行用时 :36 ms, 在所有 python3 提交中击败了94.30% 的用户
内存消耗 :12.6 MB, 在所有 python3 提交中击败了99.31%的用户
```



欢迎来github上看更多题目的解答[力扣解题思路](https://github.com/WRAllen/LeetCode)