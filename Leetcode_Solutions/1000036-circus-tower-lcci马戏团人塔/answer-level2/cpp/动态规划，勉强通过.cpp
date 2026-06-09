### 解题思路
 
![7.PNG](https://pic.leetcode-cn.com/b17b78ecd21a25e79f778bccd5523299a5a218f54be116f29c639aa0d00224a4-7.PNG)


难写了，自己看吧，很简单的

### 代码

```cpp
class Solution {
public:
	int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
		auto size = height.size();
		if (size <= 1) { return size; }
		vector<pair<int,int>> hw;
		for (int i = 0; i < size; i++) { hw.push_back(pair<int,int>(height[i], weight[i])); }
		sort(hw.begin(), hw.end(), [](pair<int, int>& a, pair<int, int>& b) {return a.second < b.second; });
		vector<set<pair<int,int> > > buff;
		auto result = 0;
		for (int i = size - 1; i >= 0; i--) {
			int rz = 1;
			int buffsize = buff.size();
			bool ok = false;
			for (int c = buffsize - 1; c >= 0; c--) {
				auto&& ms = buff[c];
				auto j = ms.lower_bound(hw[i]);
				while (j != ms.end()) {
					if (hw[i].first < (*j).first && hw[i].second < (*j).second) {
						rz = 1 + c + 1;
						ok = true;
						break;
					}
					j++;
				}
				if (ok) { break; }
			}
			if (rz >= buff.size()) {
				buff.push_back(set<pair<int,int>>());
			}
			buff[rz - 1].insert(hw[i]);
			result = max(result, rz);
		}
		return result;
	}
	
};
```