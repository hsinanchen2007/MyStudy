```java
	public int maxArea(int[] height) {
		int max = 0;
		for (int i = 0, j = height.length - 1; i < j;) {
			max = Math.max(max, (j - i) * (height[i] < height[j] ? height[i++] : height[j--]));
		}
		return max;
	}
```
