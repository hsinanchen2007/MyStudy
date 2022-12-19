核心思想：既然众数是出现次数1/2频度以上，那么若现将数组排序，中位数必为众数！
```
class Solution {
    public int majorityElement(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        
        return nums[length/2];
        
    }
}
```
