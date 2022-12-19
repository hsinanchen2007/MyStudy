### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int f(int a,int b,int c) {
		if(a+b>c&&a+c>b&&b+c>a) {
			return 1;
		}
		return 0;
	}
	public int largestPerimeter(int[] A) {
		Arrays.sort(A);
		for(int i=A.length-1;i>=2;i--) {
			if(f(A[i],A[i-1],A[i-2])==1) {
				return A[i]+A[i-1]+A[i-2];
			}
		}
		return 0;
    }
}
```