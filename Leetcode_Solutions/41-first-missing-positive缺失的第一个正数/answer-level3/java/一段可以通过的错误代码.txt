可以通过256*256+256以下缺失整数的题解
```
class Solution {
    public int firstMissingPositive(int[] nums) {
    	if(nums.length == 0) return 1;
    	int[] bit00 = new int[65536];
    	int[] bit10 = new int[65536], bit11 = new int[65536];
    	for(int i = 0; i < nums.length; i++) {
    		if(nums[i] > 0) {
    			if(nums[i] < 256*256) {
    				bit00[nums[i]]++;
    			}else if(nums[i] <= 256*256*256*128-1) {
    				bit10[nums[i]&0b1111111111111111]++;
    				bit11[(nums[i]>>16)]++;
    			}
    		}
    	}
    	int bit0to16 = 0,bit16to32l = 0, bit16to32h = 0;
    	for(int i = 1; i < 65536; i++) {
    		if(bit00[i] == 0) return i;
    		if(bit10[i] == 0 && bit0to16 == 0) bit0to16 = i;
    		if(bit10[i] < 256 && bit16to32l == 0) bit16to32l = i;
    		if(bit11[i] < 256 && bit16to32h == 0) bit16to32h = i;
    	}
    	
    	if(bit0to16 > 0) return 256*256+bit0to16;
    	if(bit16to32l > 0) return 256*256+bit16to32l;
    	return 0;
    }
}
```
