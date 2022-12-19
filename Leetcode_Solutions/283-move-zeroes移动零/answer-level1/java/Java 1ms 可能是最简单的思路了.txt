可能是最简单的思路了。
数组中每个元素需要向前移动的步数，为前面0元素的个数

class Solution {
    public void moveZeroes(int[] nums) {
        int zc = 0;
        for( int i = 0 ;i < nums.length;i++){
        	if(nums[i] == 0){
        		zc++;
        	}else{
        		nums[i-zc] = nums[i];
        		if(zc>0){
        			nums[i]=0;
        		}
        	}
        } 
    }
}