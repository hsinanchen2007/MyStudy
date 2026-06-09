### 解题思路
遍历数组平方以后排序，好像很弱啊！

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        for (int i = 0; i < A.length; i++) {
			A[i]=(int) Math.pow(A[i], 2);
		}
    	Arrays.sort(A);  
    	return A;
    }
}
```