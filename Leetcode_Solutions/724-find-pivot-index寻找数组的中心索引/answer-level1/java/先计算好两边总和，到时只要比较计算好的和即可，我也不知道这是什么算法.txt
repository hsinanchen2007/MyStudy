执行用时 :2 ms, 在所有 java 提交中击败了99.42%的用户
内存消耗 :40.5 MB, 在所有 java 提交中击败了94.21%的用户
public int pivotIndex(int[] nums) {
    	
    	if (nums.length == 1) {
    		return 0;
    	}
    	
        int []sumFront = new int[nums.length];
        int []sumBehind = new int[nums.length];
        
        int total = 0;
        for ( int i = 0; i < nums.length; i ++ ) {
        	total += nums[i];
        	sumFront[i] = total;
        }
        
        total = 0;
        for ( int i = nums.length - 1; i >= 0; i -- ) {
        	total += nums[i];
        	sumBehind[i] = total;
        }
        
        for (int i = 0; i < nums.length; i ++) {
        	if ( i == 0 ) {
        		if (sumBehind[1] == 0) {
        			return i;
        		}
        	}
        	else if ( i == nums.length - 1 ) {
        		if (sumFront[nums.length - 2] == 0) {
        			return i;
        		}
        	}
        	else {
        		if (sumFront[i - 1] == sumBehind[i + 1]) {
        			return i;
        		}
        	}
        }
        
        return -1;
    }