### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        if(nums.length == 0) return 0;
        int[] diffs = diff(nums);
        int max = 0;
        int count = 0;
        for (int i = 0; i < diffs.length; i++) {
            if(diffs[i] > 0){
                count++;
                max = Math.max(count,max);
            }else{
                count = 0;
            }
        }

        return max + 1;

    }

    public static int[] diff(int[] nums){
        int[] res = new int[nums.length -1];
        for (int i = 0; i < nums.length -1; i++) {
            res[i] = nums[i+1] - nums[i];
        }
        return res;
    }
}
```