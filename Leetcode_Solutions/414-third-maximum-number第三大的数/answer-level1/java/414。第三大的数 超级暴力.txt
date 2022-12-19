我的思路很简单，将第一大第二大第三大的数分别抽出来
这复杂度，，应该也算是O(n)吧
```
class Solution {
    public int thirdMax(int[] nums) {
        if(nums.length == 1) return nums[0];
        if(nums.length == 2) return Math.max(nums[0], nums[1]);
        long max1 = Long.MIN_VALUE;
        long max2 = Long.MIN_VALUE;
        long max3 = Long.MIN_VALUE;
        for(int i = 0; i < nums.length; i++)
        	max1 = Math.max(max1, nums[i]);
        for(int i = 0; i < nums.length; i++) 
        	if(nums[i] != max1)
        		max2 = Math.max(max2, nums[i]);
        for(int i = 0; i < nums.length; i++) 
        	if(nums[i] != max1 && nums[i] != max2)
        		max3 = Math.max(max3, nums[i]);
        
        return (max3 == Long.MIN_VALUE || max2 == Long.MIN_VALUE) ? (int)max1 : (int)max3;
    }
}
```
