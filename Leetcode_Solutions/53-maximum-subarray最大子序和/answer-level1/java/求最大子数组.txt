### 解题思路
关键点是子数组相加的和大于0，则继续加，否则子数组为当前的数组元素，同时判断当前子数组和是否大于之前的子数组和

### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int sum = nums[0];
        int result = nums[0];
        for (int i=1; i<nums.length; i++) {
            if (sum > 0) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            if (result < sum) {
                    result = sum;
            }
           
        }
        return result;

    }
}
```