### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> getLeastNumbers(vector<int>& arr, int k) {
		if (k <= 0) { return {}; }
		if (k >= arr.size()) { return arr; }
		int maxNum = 0, maxNumPos = 0;
		for (int i = 0; i < k; i++) {
			maxNumPos = i;
			maxNum = arr.at(i);
			for (int j = i + 1; j < arr.size(); j++) {
				if (arr.at(j) < maxNum) {
					maxNum = arr.at(j);
					maxNumPos = j;
				}
			}
			if (i != maxNumPos) { swap(arr.at(i), arr.at(maxNumPos)); }
		}
		vector<int> ans(arr.begin(), arr.begin()+k);
		return ans;
	}
};
```