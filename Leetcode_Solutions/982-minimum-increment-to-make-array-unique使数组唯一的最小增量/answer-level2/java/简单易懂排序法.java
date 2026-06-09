
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
		Arrays.sort(A);
		int cout =0;
		for(int i = 1;i<A.length;i++) {
			if(A[i]<=A[i-1]) {
				cout += A[i-1]+1-A[i];

				A[i]=A[i-1]+1;
			}
		}
		return cout;
    }
}
```