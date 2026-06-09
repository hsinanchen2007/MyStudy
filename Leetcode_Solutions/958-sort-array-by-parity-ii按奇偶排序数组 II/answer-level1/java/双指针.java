```
	/**类似一趟快排*/
    public int[] sortArrayByParityII(int[] A) {
        for(int i = 0, j = 1; i<A.length&&j<A.length;) {
        	while(i<A.length && (A[i] & 1) ==0) i += 2;
        	while(j<A.length && (A[j] & 1) !=0) j += 2;
        	if(i<A.length&&j<A.length) {
        		//交换
        		int temp = A[i];
        		A[i] = A[j];
        		A[j] = temp;
        		i += 2;
        		j += 2;
        	}
        }
        return A;
    }
```
