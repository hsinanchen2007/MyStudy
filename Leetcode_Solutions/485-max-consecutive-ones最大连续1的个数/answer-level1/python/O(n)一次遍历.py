### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        temp = max_one = 0;
    
        for n in nums:
            if n == 1:
               temp += 1
            else:
                max_one = max(max_one, temp);
                temp = 0;
        return max(max_one, temp); 
```

# Java
```
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int temp = 0;
        int max_ones = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                temp++;
            }
            else {
                max_ones = Math.max(max_ones, temp);
                temp = 0;
            }
        }
        return Math.max(max_ones, temp);
    }
}
```
