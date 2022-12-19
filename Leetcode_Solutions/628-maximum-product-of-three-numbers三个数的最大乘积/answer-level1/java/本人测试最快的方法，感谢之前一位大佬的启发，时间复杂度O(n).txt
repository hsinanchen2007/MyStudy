```
执行用时 :8 ms, 在所有 Java 提交中击败了82.85%的用户内存消耗 :49.7 MB, 在所有 Java 提交中击败了37.72%的用户
```

```
import java.util.Arrays;
class Solution {
    public int maximumProduct(int[] nums) {
        int [] max = new int []{Integer.MIN_VALUE, Integer.MIN_VALUE, Integer.MIN_VALUE};
        int [] min = new int []{Integer.MAX_VALUE, Integer.MAX_VALUE};
        for(int i=0;i<nums.length;i++){
            if(nums[i] > max[2])
            {
                max[0] = max[1];
                max[1] = max[2];
                max[2] = nums[i];
            }     
            else if(nums[i] > max[1] && nums[i] <= max[2])
            {
                max[0] = max[1];
                max[1] = nums[i];             
            }
            else if(nums[i] > max[0] && nums[i] <= max[1])
            {
                max[0] = nums[i];             
            }
            if(nums[i] < min[0])
            {
                min[1] = min[0];
                min[0] = nums[i];
            }
            else if(nums[i] < min[1] && nums[i] >= min[0])
            {
                min[1] = nums[i];
            }
        }
        return Math.max(max[0]*max[1]*max[2], min[0]*min[1]*max[2]);
    }
}
```
