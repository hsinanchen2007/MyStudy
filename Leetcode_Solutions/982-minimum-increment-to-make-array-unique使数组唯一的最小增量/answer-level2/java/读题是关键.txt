### 解题思路
如下

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
		Arrays.sort(A);       //先排序
		int ans=0;           //设置变量储存move数
		for (int i = 1; i < A.length; i++) {
			if (A[i]<=A[i-1]) {        
				int pre=A[i];     //设置局部变量存储A[i]之前的值
				A[i]=A[i-1]+1;    //将A[i]变为前一位的+1，实现唯一
				ans+=A[i]-pre;    //其中的差值就是move的次数，累加		
			}
		}
		return ans;
		

    }
}
```