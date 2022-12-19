深度怀疑各位大佬们疏于审题
```
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{

		for (int i = 0; i < n; i++)
		{
			nums1[m + i] = nums2[i];
		}
		sort(nums1.begin(), nums1.end());
	}
};
```
已经假设nums1足够hold两个vector啦，所以无需进行太多处理，最后使用sort一步搞定即可。

