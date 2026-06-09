之前用set统计各个数的数量，超时了，现在用map就没超时，不知道为什么。
看到官方解里面有用Boyer-Moore投票算法，太强了。
```C++ []
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int,int> m;
		map<int,int>::iterator it;
		for (int i = 0; i < nums.size(); i++) {
			if (!m.insert(pair<int, int>(nums[i], 1)).second) {
				m[nums[i]]++;
			}
		}
		for (it = m.begin(); it != m.end(); it++) {
			if (it->second > nums.size() / 2)
				return it->first;
		}
		return -1;
	}
};
```
