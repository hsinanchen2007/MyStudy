### 解题思路
1. 除0外，如果有重复则返回false
2. 除0外，如果最大值-最小值<=4，那么返回true，否则返回false

### 代码

```java
class Solution {
    private static final int paperNumber = 5;
    public boolean isStraight(int[] nums) {
        //除0外，有重复则返回false
        Arrays.sort(nums);
        int max = nums[paperNumber - 1];
        int min = Integer.MAX_VALUE;
        for(int i = 0; i < paperNumber - 1; i++){
            if(nums[i] != 0){
                if(nums[i] == nums[i + 1]){
                    return false;
                }
                min = Math.min(min, nums[i]);
            }
        }

        //除0外，最大值-最小值<=4，则返回true，否则返回false
        return min == 0 || max - min <= 4 ? true : false;
    }
}
```