```java
class Solution {
    public int majorityElement(int[] nums) {
        int majority = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == majority)
                count++;
            else {
                if (count > 1)
                    count--;
                else {
                    count = 1;
                    majority = nums[i];
                }
            }
        }
        return majority;
    }
}
```