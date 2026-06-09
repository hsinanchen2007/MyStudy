### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> buff;
	int jump(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		buff.clear();
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] <= 0) buff.push_back(-1);
			else buff.push_back(i + nums[i]);
		}
		return merge(nums,0);
	}

	int merge(vector<int>& nums, int beg) {
		int end = nums.size() - 1;
		int mid = buff[beg];
		if (mid >= end)
			return 1;
		if (end - beg <= 1)
			return 0;
		auto fd = max_element(buff.begin() + beg + 1, buff.begin() + mid+1);
		mid = fd - buff.begin();
		return 1 + merge(nums,mid);
	}

};
```