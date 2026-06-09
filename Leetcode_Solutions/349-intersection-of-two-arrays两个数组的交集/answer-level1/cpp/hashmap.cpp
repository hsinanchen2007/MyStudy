### 解题思路
很容易想到，用一个HashMao保存数组1中出现的元素，其次遍历数组2，将存在于hashmap中元素标记出来即为输出的交际元素。

### 代码

```cpp
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		set<int>s;
		unordered_map<int, int> m;
		for (auto n1 : nums1) m[n1]=1;
		for (auto n2 : nums2) {
			if (m[n2])s.insert(n2);
		}
		for (set<int>::iterator it = s.begin(); it != s.end(); it++)
		{
			res.push_back(*it);
		}
		return res;
	}
};

```