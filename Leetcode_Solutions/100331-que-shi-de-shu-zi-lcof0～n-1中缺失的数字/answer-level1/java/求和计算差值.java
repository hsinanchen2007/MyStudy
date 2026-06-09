```java
class Solution {
    public int missingNumber(int[] nums) {
        int k = nums.length;
        int total = k * (k+1) / 2;
        int sum = 0;
        for(int i = 0; i < nums.length; i++){
            sum+=nums[i];
        }

        return total - sum;
    }
}
```