### 解题思路
此处撰写解题思路

### 代码
从前向后遍历,对于每一个元素都有取或者不取两种选择,记录当前步骤的最大值,并且记下选取当前元素后的最大值和最小值防止后面出现变数.


```java
class Solution {
    
  public int maxProduct(int[] nums) {
        int l = nums.length;
        int max = nums[0];
        int min = nums[0];
        int preMax = nums[0];
        int temp;
        for (int i = 1; i < l; i++) {
            if (nums[i] > 0) {

                max = Math.max(nums[i] * max, nums[i]);
                min = Math.min(nums[i] * min, nums[i]);
            } else {
                temp = max;
                max = Math.max(nums[i] * min, nums[i]);
                min = Math.min(nums[i], nums[i] * temp);
            }
            preMax = Math.max(max, preMax);
        }
        return preMax;
    }
}
```