# Java

pyton 写多了 回头写java
发现 if (nums[i] == nums[j] == 0)
**报错**

```
class Solution {
    public void moveZeroes(int[] nums) {
        int j = 0;
        for(int i = 0; i < nums.length; i++) {
            if (nums[i] == 0 && nums[j] == 0) {
                continue;
            }
            else {
                if (i == j) {
                    j += 1;
                }
                else {
                    nums[j] = nums[i];
                    nums[i] = 0;
                    j += 1;
                }
            }
        }
    }
}


```

# Python 两个版本 第一个思路一般
```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0;
        for i in range(len(nums)):
            if nums[i] == nums[j] == 0:
                continue;
            if nums[j] == 0 and nums[i] != 0:
                nums[j] = nums[i];
                nums[i] = 0;
                j += 1;
            if nums[j] != 0 and nums[i] != 0:
                j += 1;
                continue;
        return nums;
```

```
class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0;
        for i in range(len(nums)):
            if nums[i] == nums[j] == 0:
                continue
            else:
                if i == j:
                    j += 1;
                else:
                    nums[j] = nums[i];
                    nums[i] = 0;
                    j += 1;
        return nums;
```
