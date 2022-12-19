### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int trap(vector<int>& height) {
		int left = 0, right = 0, area = 0;
		int high = 0;
		if (height.size() < 3)
			return area;

		std::vector<int> peak;
		if (height[0] >= height[1])
			peak.push_back(0);
		for (int i = 1; i < height.size()-1; i++) {
			if (height[i] >= height[i - 1] && height[i] >= height[i + 1])
				peak.push_back(i);
		}
		if (height[height.size() - 1] >= height[height.size() - 2])
			peak.push_back(height.size() - 1);

		int N = peak.size();
		std::vector<int> leftmax(N, height[peak[0]]), rightmax(N, height[peak[N - 1]]);
		

		if (peak.size() >= 2) {
			for (int i = 1; i < peak.size(); i++) {
				leftmax[i] = std::max(leftmax[i - 1], height[peak[i]]);
				rightmax[N - 1 - i] = std::max(rightmax[N - i], height[peak[N - 1 - i]]);
			}
			//for (int i = 0; i < N; i++) {
			//	std::cout << leftmax[i] << "\t" << rightmax[i] << std::endl;
			//}
				
			for (int i = 0; i < peak.size()-1; i++) {
				high = std::min(leftmax[i], rightmax[i + 1]);
				for (int j = peak[i]; j < peak[i + 1]; j++)
					area += std::max(0, high - height[j]);
				//area += std::min(height[peak[i]], height[peak[i + 1]])*(peak[i + 1] - peak[i] - 1)
				//	- std::accumulate(height.begin() + peak[i] + 1, height.begin() + peak[i + 1], 0);
			}
		}
		return area;
	}
};
```