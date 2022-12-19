```
class Solution {
    public int dominantIndex(int[] nums) {
    	if(nums.length == 1) {
    		return 0;
    	}
        
    	int index = 0;  //保存最大数字的下标
        int max2=-1;  //保存第二大的数字
        
        for(int i=0; i<nums.length; i++) {
        	if(nums[i] > nums[index]) {  //如果大于最大数
        		max2 = nums[index];
        		index=i;
        	}
        	else if( i>0 && nums[i] > max2) {
        		max2=nums[i];
        	}
        }
      
        return 2*max2>nums[index] ? -1 : index;
    }
}
```
测试了好多用例都不通过，发现问题是第一个数字就是最大数，于是第二个else if 执行的时候将最大值直接赋值给了max2(第二大的数字).
加了一个限定条件i>0解决
