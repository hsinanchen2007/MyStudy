```
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> vec;
		for (int i = 0; i < nums1.size(); i++)
		{
			vec.push_back(nums1[i]);
		}
		for (int i = 0; i < nums2.size(); i++)
		{
			vec.push_back(nums2[i]);
		}
		sort(vec.begin(),vec.end());
		int len = vec.size();
		double out;
		if (len % 2 == 0)
		{
			out = vec[len / 2] + vec[len / 2 - 1];
			out = out / 2;
			return out;
		}
		else
		{
			out = vec[(len - 1) / 2];
			return out;
		}

	}
};
```
