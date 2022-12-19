执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :35.5 MB, 在所有 java 提交中击败了36.86%的用户
public static int[] plusOne(int[] digits) {
    	Boolean bJin = true;
    	for (int i = digits.length - 1; i >= 0; i --) {
    		
    		int value = digits[i];
    		if ( bJin ) {
    			value ++;
    		}
    		
    		if (value >= 10) {
    			digits[i] = value - 10;
    			bJin = true;
    		}
    		else {
    			digits[i] = value;
    			bJin = false;
    		}
    	}
    	
    	if (bJin) {
    		int []arr = new int[digits.length + 1];
    		arr[0] = 1;
    		for (int i = 1; i < arr.length; i ++) {
    			arr[i] = digits[i - 1];
    		}
    		
    		return arr;
    	}
    	else {
    		return digits;
    	}
    }