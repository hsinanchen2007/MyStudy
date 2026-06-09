### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean increasingTriplet(int[] nums) {
        int min_num = Integer.MAX_VALUE;
        int sec_num = Integer.MAX_VALUE;
        for (int i=0;i<nums.length;i++){
           min_num = Math.min(nums[i],min_num);
           if(nums[i]>min_num) sec_num=Math.min(nums[i],sec_num);
           if(nums[i]>sec_num) return true;
        }
        return false;
    }
}
```