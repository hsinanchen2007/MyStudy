### 解题思路
终于又做出来一题！！！
排序加复制数组搞定！

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
    	int[]ans = new int[k];
    	Arrays.sort(arr);
    	System.arraycopy(arr, 0, ans, 0, k);
		return ans;  	
    }
}
```