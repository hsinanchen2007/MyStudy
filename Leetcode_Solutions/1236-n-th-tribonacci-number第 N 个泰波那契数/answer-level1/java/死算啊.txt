一项项加起来
执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :33.7 MB, 在所有 java 提交中击败了100.00%的用户
public int tribonacci(int n) {
       if ( n == 0 ) {
    		return 0;
    	}
    	if ( n == 1 ) {
    		return 1;
    	}
    	if ( n == 2 ) {
    		return 1;
    	}
    	
        int []arr = new int[n + 1];
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        
        int value1 = 0;
        int value2 = 1;
        int value3 = 1;
        for (int i = 3; i < n + 1; i ++) {
        	arr[i] = value1 + value2 + value3;
        	value1 = value2;
        	value2 = value3;
        	value3 = arr[i];
        }
        
        return arr[n];
    }