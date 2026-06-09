### 解题思路
1、定义sum、maxValue记录目前窗口的和和最大值
2、sum<0的丢弃

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        // 滑动窗口
        int maxValue = Integer.MIN_VALUE;
        int sum = 0;
        for (int start = 0, end = 0; end < nums.length; end++){
            sum += nums[end];
            if (sum > maxValue){
                maxValue = sum;
            }
            if (sum < 0){ // 小于0的不要
                sum = 0;
                start++;
            }        
        }
        return maxValue;
    }
}
```