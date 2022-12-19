笨方法，拷贝一份数组，将原数组排序，与拷贝数组比较，有几个不一样的元素

代码：
```
class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int ans = 0;
		int len = heights.size();
		vector<int> copy(len);
		for (int i = 0; i < len; i++)
			copy[i] = heights[i];
		sort(heights.begin(), heights.end());
		for (int i = 0; i < len; i++) {
			if (heights[i] != copy[i])
				ans++;
		}
		return ans;
	}
};
```
