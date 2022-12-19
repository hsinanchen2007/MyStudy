### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int maxArea(vector<int>& height) {
		int maxVolume = 0;
		for (int i = 0, j = height.size() - 1; i < j;) {
			int curMinHeight = min(height[i], height[j]);
			maxVolume = max(maxVolume, (j - i)*curMinHeight);
			if (curMinHeight == height[i]) { i++; }
			else { j--; }
		}
		return maxVolume;
	}
};
```