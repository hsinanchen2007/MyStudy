### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for(int i=0; i<A.length; i++){
			for(int p=0,q=A[i].length-1; p<=q; p++,q--){
				int temp = A[i][p];
				A[i][p] = A[i][q]==1 ? 0 : 1;
				A[i][q] = temp==1 ? 0 : 1;
			}
		}
		return A;
    }
}
```