### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        i = j = 0;
        for i in range(len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]
                j += 1;
            else:
                continue;
        return j
```

# Java
```
class Solution {
    public int removeElement(int[] nums, int val) {
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                j++;
            }
            else {
                continue;
            }
        }
        return j;
    }
}
```
