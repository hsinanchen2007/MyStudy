### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxArea(int[] height) {
        if(height==null || height.length<2)
			return 0;
		
		int len = height.length;
		int max = 0;
		for (int i = 0; i < len-1; i++) {
			for (int j = i+1; j < height.length; j++) {
				int h = (height[i]<height[j])?height[i] : height[j];
				int area = h * (j - i);
				if(area > max) {
					max = area;
				}
			}
		}
		return max;
    }
}
```
![image.png](https://pic.leetcode-cn.com/edcf7a6a16b198b36c2ca7ee6c9b7665bd8357dfcdf7a718811ca004bb6d313b-image.png)
