```
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		map<int, int> keyvalue;
		vector<int> result;
		for (auto iter = nums2.begin(); iter != nums2.end(); iter++)//遍历nums2每个数字
		{
			auto iterfind = iter;
			for (iterfind += 1; iterfind != nums2.end(); iterfind++)//从nums2当前数字往后找一个比它大的数
			{
				if (*iterfind > *iter)
				{
					keyvalue.insert({ *iter,*iterfind });           //存入map，便于nums1直接查找
					break;
				}
			}
			if(iterfind==nums2.end())                               //如果全找完了都没找到比他大的，就给个-1值
				keyvalue.insert({ *iter,-1 });
		}
		for (auto c : nums1)                                        //枚举nums1各个值，将其结果存入vector。
		{
			result.push_back(keyvalue[c]);
		}
		return result;
	}
};
```
