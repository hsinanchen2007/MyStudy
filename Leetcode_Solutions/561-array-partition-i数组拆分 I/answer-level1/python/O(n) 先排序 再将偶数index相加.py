### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def arrayPairSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(nums)
        i = sum = 0
        while i < (len(nums)):
            sum += nums[i]
            i += 2
        return sum
```

# Java
```
class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int i = 0;
        int sum = 0;
        while(i < nums.length) {
            sum += nums[i];
            i += 2; 
        }
        return sum;

    }
}
```
