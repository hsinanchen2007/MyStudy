按照顺序来遍历肯定不行的，时间溢出。
我是用了二分查找法，查找前一个数据isBadVersion返回false，当前数据isBadVersion返回为true的数据。
以下函数c++和java都可以提交，执行用时0ms。

执行用时 :0 ms, 在所有 cpp 提交中击败了100.00%的用户
内存消耗 :8.1 MB, 在所有 cpp 提交中击败了61.29%的用户

public static int firstBadVersion(int n) {
    	
    	if( isBadVersion(1) ) {
    		return 1;
    	}
    	
    	if( isBadVersion(n) && !isBadVersion(n - 1)) {
    		return n;
    	}
    	
    	int head = 1;
    	int tail = n; 
    	int index = head / 2 + tail / 2;
    	while ( index > 0 ) {
    		if( !isBadVersion(index) ) {
    			head = index;
    		}
    		else {
    			tail = index;
    		}
    		
        	index = head / 2 + tail / 2;
        	if (head % 2 != 0 && tail % 2 != 0) {
        		index += 1;
        	}
    		if ( !isBadVersion(index) && isBadVersion(index + 1) ) {
    			return index + 1;
    		}
    	}
        
        return 0;
    }