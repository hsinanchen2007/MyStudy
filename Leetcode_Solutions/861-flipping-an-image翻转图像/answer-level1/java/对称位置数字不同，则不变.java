### 解题思路
如果对称位置两个数相同，则0 1 互换。

### 代码

```java
class Solution {
	public int[][] flipAndInvertImage(int[][] A) {
		int n=A[0].length;
		int mid=(n-1)/2;
		for(int i=0;i<A.length;++i) {
			for(int j=0;j<=mid;++j) {
				if(A[i][j]==A[i][n-j-1]) {
					A[i][j]=1-A[i][j];
					A[i][n-j-1]=A[i][j];
				}
			}
		}
		return A;
	}
}
```