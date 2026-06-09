### 解题思路
这道题用双指针的难点在于，如何让sum-target（即答案中的res）的值顺利取到正确的初始值。所以我将res分成大于0 和 小于0 两种情况，最后通过绝对值（即到target的距离），取较小的res。另外java语法细节：Integer.MAX_VALUE 或者 Integer.MIN_VALUE的绝对值还是本身


### 代码

```java
class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        if(nums.length == 3){
            return nums[0] + nums[1] + nums[2];
        }
        int res1 = Integer.MAX_VALUE - 1;
        int res2 = Integer.MIN_VALUE + 1;
        int sum;
        for (int i = 0; i < nums.length; i++) {
            int j = i + 1;
            int k = nums.length - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if(sum - target > 0){
                    res1 = Integer.min(res1, sum - target);
                }
                else if(sum - target < 0){
                    res2 = Integer.max(res2, sum - target);
                }
                if (sum > target) {
                    k--;
                }
                else if (sum < target) {
                    j++;
                } else{
                    return sum;
                }
            }
        }
        //res = sum - target
        
        if(Math.abs(res1) < Math.abs(res2)){
            return res1 + target;
        }else{
            return res2 + target;
        }
    }
}
```