执行用时 :4 ms, 在所有 C++ 提交中击败了98.43%的用户
内存消耗 :11.8 MB, 在所有 C++ 提交中击败了5.21%的用户

### 代码

```cpp

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
	{
		vector<int> res;
		unordered_set<int> myset;
		for (int i = 0; i < nums1.size(); i++)
			myset.insert(nums1[i]);
		for (int i = 0; i < nums2.size(); i++)
		{
			if (myset.find(nums2[i]) != myset.end())
			{
				res.push_back(nums2[i]);
				myset.erase(nums2[i]);
			}
		}
	    return res;
    }
};
```