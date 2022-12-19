### 解题思路
双指针左右缩进法。
题目求得是，面积得最大，我们假设指针i=0，j=length-1，即两边向中间靠拢为最大得可能，每次左或者右向中间靠拢。

### 代码

```java
class Solution {
    public int maxArea(int[] a) {
        int max = 0;
		 for(int i = 0, j = a.length - 1; i < j ; ){
			 int minHeight = a[i] < a[j] ? a[i ++] : a[j --];
			 max = Math.max(max, (j - i + 1) * minHeight);
		 }
		 return max;
    }
}
```