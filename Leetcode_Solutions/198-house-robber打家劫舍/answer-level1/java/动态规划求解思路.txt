### 解题思路
假设第i个房间的金额为A(i),能偷到的最大金额为f(i),那么有下述递推公式：f(i) = max(f(i-1),f(i-2) + A(i))
### 代码

```java
class Solution {
    public int rob(int[] nums) {
      if (nums.length ==0){
            return 0;
        }
        if (nums.length == 1){
            return nums[0];
        }
        if (nums.length == 2){
            return Math.max(nums[0],nums[1]);
        }

        int max = 0;
        int []maxResults = new int[nums.length];
        maxResults[0] = nums[0];
        maxResults [1] = Math.max(nums[0],nums[1]);
        for (int i=2; i< nums.length ; i++){
            max = Math.max(maxResults[i-1],nums[i]+ maxResults[i-2]);
            maxResults[i] = max;
        }
        return max;
    }
}
```