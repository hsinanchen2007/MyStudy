### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] arr=new int[queries.length];
        int sum=0;
    	for(int j=0;j<A.length;j++) {
    		if(A[j]%2==0) {
    			sum+=A[j];
    		}
    	}
		for(int i=0;i<queries.length;i++) {
			if(A[queries[i][1]]%2==0) {
				if((A[queries[i][1]]+queries[i][0])%2==0) {
					sum+=queries[i][0];
				}else {
					sum-=A[queries[i][1]];
				}
			}else {
				if((A[queries[i][1]]+queries[i][0])%2==0) {
					sum+=A[queries[i][1]]+queries[i][0];
				}
			}
        	A[queries[i][1]]=A[queries[i][1]]+queries[i][0];
//        	for(int j=0;j<A.length;j++) {
//        		System.out.print(A[j]+" ");
//        	}
//        	System.out.println();
        	arr[i]=sum;
        }
		return arr;
    }
}
```