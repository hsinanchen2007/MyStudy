
遍历出所有的子序列(～￣(OO)￣)ブ
估计会被经理撵走
```
class Solution {
    public int maxSubArray(int[] nums) {
    	int tempSum = 0;
    	int arr = Integer.MIN_VALUE ;
    	for (int j = 0; j < nums.length; j++) {
    		tempSum = 0;
        	for (int i = j; i < nums.length; i++) {
    			tempSum = tempSum + nums[i];
    			if(tempSum > arr){
    				arr = tempSum;
    			}
    		}			
		}
    	return arr;
    
    }
}
```