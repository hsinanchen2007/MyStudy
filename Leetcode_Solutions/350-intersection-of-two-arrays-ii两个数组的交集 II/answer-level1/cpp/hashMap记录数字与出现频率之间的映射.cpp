### 解题思路
hashMap记录数字与出现频率之间的映射

### 代码

```cpp
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		unordered_map<int, int> m;
		for (auto n : nums1) ++m[n];
		for (auto a : nums2) {
			if (m[a]) {
				res.push_back(a); m[a]--;
			}
		}
		return res;
	}
};
```