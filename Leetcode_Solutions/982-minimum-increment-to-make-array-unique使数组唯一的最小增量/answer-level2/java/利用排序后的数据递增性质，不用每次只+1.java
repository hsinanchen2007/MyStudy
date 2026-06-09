### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
      int res = 0;
		if (A.length == 0)
			return res;
		Arrays.sort(A);
		int p=A[0];
		for (int i = 1; i < A.length; i++) {
			if(A[i]<=p) {
				res+=p+1-A[i];
				A[i]=p+1;
			}
			p=A[i];
		}
		return res;
    }
}
```