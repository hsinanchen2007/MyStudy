1.递增、递减、差值为0的等差数列;
2.方法一,如果是递增数列,asc == A.length - 1,递减数列则相反;
3.如果是常数数列,asc == A.length - 1 并且 desc == A.length - 1,返回true;
4.方法二,根据boolean判断,数组中既有递增情况,又有递减情况,则返回false,反之true;
5.完结。


	//法一：
        public boolean isMonotonic(int[] A) {
		int asc = 0, desc = 0;
		for (int i = 0; i < A.length - 1; i++) {
			if (A[i] <= A[i + 1]) {
				asc++;
			}
			if (A[i] >= A[i + 1]) {
				desc++;
			}
		}
		return asc == A.length - 1 || desc == A.length - 1;
	    }

	//法二：
        public boolean isMonotonic(int[] A) {
		boolean asc = false, desc = false;
		for (int i = 0; i < A.length - 1; i++) {
			if (A[i] < A[i + 1]) {
				asc = true;
			}
			if (A[i] < A[i + 1]) {
				desc = true;
			}
			if (asc && desc) {
				return false;
			}
		}
		return true;
	    }