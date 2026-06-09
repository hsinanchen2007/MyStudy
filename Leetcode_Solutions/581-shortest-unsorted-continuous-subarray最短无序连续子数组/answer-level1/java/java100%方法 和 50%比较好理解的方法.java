```
/** 100% */
class Solution {
    public int findUnsortedSubarray(int[] nums) {
    	int len = nums.length;
        int l = nums.length - 1;
        int r = 0;
        int min = nums[l];
        int max = nums[r];
        
        /** 其实可以拆成两个循环 */
        for (int i = 0; i < len; i ++) {
        	if (nums[i] < max) {
        		r = i;
        	}
        	
        	else {
        		max = nums[i];
        	}
        	
        	if (nums[len - 1 - i] > min) {
        		l = len - 1 - i;
        	}
        	else {
        		min = nums[len - 1 - i];
        	}
        }
        
        return r > l ? r - l + 1 : 0;
    }
}

/** 50% */
class Solution {
    public int findUnsortedSubarray(int[] nums) {
        int[] tmp = Arrays.copyOf(nums, nums.length);
        Arrays.sort(tmp);
        int start = -1;
        int end = -1;
        
        for (int i = 0; i < nums.length; i ++) {
        	if (nums[i] != tmp[i]) {
        		start  = i;
        		break;
        	}	
        }
        
        if (start == -1)
        	return 0;
        
        for (int j = nums.length - 1; j >= 0; j --) {
        	if (nums[j] != tmp[j]) {
        		end = j;
        		break;
        	}
        }
        
        return end - start + 1;
    }
}