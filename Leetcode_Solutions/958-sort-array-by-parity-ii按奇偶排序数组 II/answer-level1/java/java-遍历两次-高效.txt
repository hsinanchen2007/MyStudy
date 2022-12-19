```
		int[] result = new int[A.length];
		int size = A.length;
		//奇数数组
        int[] temp1 = new int[size / 2];
        int t1 = 0;
        int t2 = 0;
        //偶数数组
        int[] temp2 = new int[size / 2];
		for (int i = 0; i < A.length; i++) {
			if (A[i] % 2 == 0) {
				temp2[t2++] = A[i];
				continue;
			}
			temp1[t1++] = A[i];
		}
		t1 = 0;
        t2 = 0;
        for (int i = 0; i < result.length; i++) {
        	if (i % 2 == 0) {
        		result[i] = temp2[t2++];
        		continue;
        	}
        	result[i] = temp1[t1++];
		}
## 		return result;
```
