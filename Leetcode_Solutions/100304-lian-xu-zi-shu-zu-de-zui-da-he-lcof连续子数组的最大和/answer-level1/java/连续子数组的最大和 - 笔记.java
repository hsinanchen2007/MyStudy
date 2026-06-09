### 解题思路
当sum小于零的时候就将sum置为0.相当于前面的位置都不合法，全部清空掉，从新的位置开始算

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = 0;
        int max = Integer.MIN_VALUE;

        // 时间复杂度O(n)
        for(int i = 0, len = nums.length; i < len; i++){
            sum += nums[i];
            // 比较当前sum与max
            if(sum > max)
                max = sum;
            // 当sum小于零的时候就将sum置为0.相当于前面的位置都不合法，全部清空掉，从新的位置开始算
            if(sum < 0)
                sum = 0;
        }
        return max;
    }
}
```