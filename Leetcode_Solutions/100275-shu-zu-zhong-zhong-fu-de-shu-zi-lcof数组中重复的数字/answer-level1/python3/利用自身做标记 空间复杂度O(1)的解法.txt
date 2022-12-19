很容易想到的做法是用数组或哈希表做标记，这样空间复杂度是O(N)。
然后看到其他人题解中的代码，有个做法是利用自身做标记，这样空间复杂度是O(1)，我也写了一下。

```
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if nums[i] != i:
                if nums[nums[i]] == nums[i]:
                    return nums[i]
                else:
                    t = nums[i]
                    nums[i], nums[t] = nums[t], nums[i]
        return -1
```
思路：遍历每一个元素，把它放到它该放的位置，如果位置被占了，说明重复了。

LC41跟这道题很像，也是利用自身做标记：https://leetcode-cn.com/problems/first-missing-positive/