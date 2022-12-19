### 解题思路
看到数组及频率，我首先想到用map，后面说用升序排列，所以没用unordered_map

### 代码

```cpp
class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> res;
		map<int, int> m;//<num,count>;
		for (auto n: arr1) ++m[n];
		for (auto a : arr2) {
			while (m[a]--) res.push_back(a);
            m.erase(a);
		}
		for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
			while ((it->second)--) res.push_back(it->first);
		}
		return res;
	}
};
```