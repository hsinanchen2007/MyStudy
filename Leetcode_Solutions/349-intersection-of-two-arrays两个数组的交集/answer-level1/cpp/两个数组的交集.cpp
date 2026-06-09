根据交集的性质,我选择先对数组nums1去重,然后遍历nums1数组的元素,使用count()函数,若nums1中的元素在nums2数组中出现的,即是我们要的结果,具体代码如下:
```
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
		if (nums1.empty() || nums2.empty())
			return res;
		else {
			sort(nums1.begin(), nums1.end());
			nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
			for (int i = 0; i < nums1.size(); i++) {
				if (count(nums2.begin(), nums2.end(), nums1[i]))
					res.push_back(nums1[i]);
			}
			return res;
		}
    }
};
```