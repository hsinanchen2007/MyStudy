执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :34.9 MB, 在所有 Java 提交中击败了100.00%的用户
public int[] sumZero(int n) {
        int []zero = new int[n];
    	int index = 0;
        for (int i = - n / 2; i <= n / 2; i ++) {
        	if (i == 0) {
        		if (n % 2 != 0) {
        			zero[index] = i;
        			index ++;
        		}
        	}
        	else {
        		zero[index] = i;
        		index ++;
        	}
        }
        
        return zero;
    }