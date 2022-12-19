### 解题思路
**解题关键：**
1.双指针向中间逼近
2.指针移动条件：移动两端更短的指针
**理解：** 
（1）area=h*w;开始w取最大值，指针移动过程中，w一定减小；
（2）假设h[left],h[right]为某时刻两端高度且h[right]>h[left]，h是取两端更小值，h=min{h[left],h[right]}=h[left]若移动right,再次更新h,h=min{h[left],h[right-1]}<h[left] 所以移动更长高度的指针没有意义。每次移动更短边，才有可能面积增大。

### 代码

```cpp
class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area=0; 
		int left, right;//左右指针
		left= 0,
		right=height.size() - 1;
	
		while (left<right) {
			max_area = max(max_area, (right - left) * min(height[left], height[right]));
			if (height[left] < height[right])left++;
			else right--;
		}
		return max_area;
	}
	int max(int a, int b) {
		return a > b ? a : b;
	}
	int min(int a, int b) {
		return a < b ? a : b;
	}

};
```