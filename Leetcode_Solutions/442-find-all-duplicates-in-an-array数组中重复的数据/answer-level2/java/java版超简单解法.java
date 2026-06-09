### 解题思路
1. 找到数字`i`时，将位置`i-1`处的数字翻转为负数。
2. 如果位置`i-1` 上的数字已经为负，则`i`是出现两次的数字。
    

### 代码

```java
class Solution {
    
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < nums.length; ++i) {
            int index = Math.abs(nums[i])-1;
            if (nums[index] < 0)
                res.add(Math.abs(index+1));
            nums[index] = -nums[index];
        }
        return res;
    }
}
```