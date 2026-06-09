### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        if (nums.length <= 2) {
            return 0;
        }
        int i = 0;
        int sum = 0;
        while (i < nums.length) {
            int o = nums[i+1] - nums[i];
            int j = i+1;
            while (j < nums.length && nums[j] - nums[j-1] == o){
                ++j;
            }
            if (j-i >= 3) {
                sum +=count(j-i);
            }
            if (j == nums.length) {
                break;
            }
            i = j-1;
        }
        return sum;
    }

     private int count(int n) {

        int sum = 0;
        int dp = 0;
        while (n - 3 >= 0) {
            sum +=++dp;
            --n;
        }
        return sum;
    }
}
```