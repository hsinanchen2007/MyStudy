```
class Solution {
public:
	int maxArea(vector<int>& height) {
		int len = height.size();
		int Max = 0;
		int l = 0; int r = len - 1;
		while (r>l)
		{
			Max = max(Max, min(height[l], height[r]) * (r - l));
			if (height[l] > height[r])
			{
				r--;
			}
			else
			{
				l++;
			}
		}
		return Max;
	}
};
```
