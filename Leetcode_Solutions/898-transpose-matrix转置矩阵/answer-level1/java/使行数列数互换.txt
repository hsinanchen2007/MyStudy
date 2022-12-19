### 解题思路
使行数列数互换:B.length=A[0].length ; B[0].length=A.length;

### 代码

```java
class Solution {
    public int[][] transpose(int[][] A) {
      int [][]B =new int [A[0].length][A.length];
		for(int i=0;i<B.length;i++){
			for(int j=0;j<B[i].length;j++){
				B[i][j]=A[j][i];
			}
		}
		return B;
    }
}
```