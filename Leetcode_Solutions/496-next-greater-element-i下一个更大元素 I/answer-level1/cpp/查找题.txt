### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res(nums1.size());
		unordered_map<int, int> m; //<num,position>
		int pos = 0;
		for (auto i : nums2) 	m[i] = pos++;
		for (int k = 0; k < nums1.size();k++) {
			res[k] = -1;
			
				for (int j = m[nums1[k]] + 1; j < nums2.size(); j++) {
					if (nums2[j] > nums1[k]) {
						res[k] = nums2[j];
						break;
					}
				}
			
		}
		return res;
	}
};
```