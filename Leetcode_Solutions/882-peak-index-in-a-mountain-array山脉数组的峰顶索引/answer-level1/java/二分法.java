二分查找峰值
执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :42.6 MB, 在所有 java 提交中击败了48.39%的用户
public int peakIndexInMountainArray(int[] A) {
        int head = 0;
    	int tail = A.length - 1; 
    	int index = head + (tail - head ) / 2;
    	while ( index > 0 ) {
    		if ( index == 0 ) {
    			if(A[index] > A[index + 1]) {
    				return index;
    			}
    		}
    		
    		else if ( index == A.length - 1 ) {
    			if(A[index] > A[index - 1]) {
    				return index;
    			}
    		}
    		
    		else {
    			if( A[index] < A[index + 1] ) {
    				head = index;
    			}
    			else if ( A[index] < A[index - 1] ) {
    				tail = index;
    			}
    			else if ( A[index] >= A[index + 1] && A[index] >= A[index - 1]) {
    				return index;
    			}
    		}
    		
    		index = head + (tail - head) / 2;
    	}
        
        return 0;
    }