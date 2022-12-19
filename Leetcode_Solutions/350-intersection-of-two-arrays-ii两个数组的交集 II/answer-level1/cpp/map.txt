执行用时 :8 ms, 在所有 C++ 提交中击败了78.92%的用户
内存消耗 :12.1 MB, 在所有 C++ 提交中击败了5.15%的用户

### 代码

```cpp
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		unordered_map<int, int> mymap;
		vector<int> res;
		for (int i = 0; i < nums1.size(); i++)
		{
			mymap[nums1[i]]++;
		}
		for (int i = 0; i < nums2.size(); i++)
		{
			if (mymap[nums2[i]] != 0)
			{
				res.push_back(nums2[i]);
				mymap[nums2[i]]--;
			}
		}
		return res;

	}
};
```