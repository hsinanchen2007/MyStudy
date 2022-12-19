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
		
		//定义左右两边的指针
		int left = 0;
		int right = len - 1;
		while(left < right) {
			int h = (height[left] > height[right])?height[right] : height[left];
			int area = h * (right - left);
			if(area > max) {
				max = area;
			}
			if(height[left] > height[right]) {
				right --;
			}else {
				left ++;
			}
		}
		return max;
    }
}
```

![image.png](https://pic.leetcode-cn.com/2bcaf788db0140780b6434d13dcb49eb11b743ca285fbc25d1ba5f1a6a87d113-image.png)
