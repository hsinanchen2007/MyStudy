### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int [] answer=new int[queries.length];
		int currentSum=0;
		for(int i=0;i<A.length;i++){
			if(A[i]%2==0)
				currentSum+=A[i];
		}
		for(int i=0;i<queries.length;i++){
			int val = queries[i][0], index = queries[i][1];
            if(A[index]%2==0)
			    currentSum-=A[index];
			A[index]=val+A[index];
			if(A[index]%2==0){
				answer[i]=currentSum+A[index];
                currentSum=answer[i];
            }
            else
                answer[i]=currentSum;
		}
		return answer;
    }
}
```