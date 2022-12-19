### 解题思路
根据题意，可以先排序，对于i位置，假设此时已经加到的最小值为min，次数为count，则对于i+1，分两种情况讨论1.如果A[i+1] <= min，说明A[i+1]至少要加到比min大1的数才能保证不会重复（即min+1）
2.如果A[i+1] > min，说明i+1之前已经产生的最小数与A[i+1]无关，此时直接从i+1开始，把A[i+1]作为新的最小数即可
注意：上述情况成立的前提是A数组经过排序了的，另外，对于排序算法那一块，也许可以优化一下。。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length <= 0) {
		 		return 0;
		 	}
	        Arrays.sort(A);
			//count表示加的次数
	        int count = 0;
			//min表示已经加到的最小数，比如:1,1,2,2,3，到第4个数（第2个2）的时候，min为3
	        int min = A[0];
	        for(int i=1; i<A.length; i++){
	        	if(A[i] <= min) {
	        		count += min - A[i] + 1;
	        		min += 1;
	        	}else {
	        		min = A[i];
	        	}
	            
	        }
	        return count;
    }
}
```