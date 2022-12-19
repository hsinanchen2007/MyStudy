### 解题思路
第一步：ij两边指针；
第二步：max=min([i],[j])*(j-i);
第三步：[i++]>=min([i],[j]),[k--]>=min([i],[j])

时间复杂度O(n);

滑动窗口思想，只要保证每次向内寻找的都是比之前第一大的值即可；

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
		int len = 0;
		if (height == null || (len = height.length) < 2) {
			return 0;
		}
		int i = 0, j = len - 1;
		int max = 0;
		int min = 0;
		while (i < j) {
			min = Math.min(height[i], height[j]);
			max = Math.max(max, min * (j - i));
			while (i < j && height[i] <= min) {
				i++;
			}
			while (j > i && height[j] <= min) {
				j--;
			}
		}
		return max;
    }
}
```