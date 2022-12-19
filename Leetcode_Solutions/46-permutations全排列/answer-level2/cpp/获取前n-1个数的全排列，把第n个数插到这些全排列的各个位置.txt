下面代码里虽然用了两个容器res和tmp存储全排列结果并且还在每加入一个数后将tmp赋给了res，调用了一次拷贝构造函数，产生了巨大的时间代价，但仍然执行用时超过了50%的用户。改进一下直接res和tmp交替使用会更好，改进后的代码附在后面。
```C++ []
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res, tmp;
		vector<int> v(1,nums[0]);
		res.push_back(v);
		for (int i = 1; i < nums.size(); i++) {
			for (auto v : res) {
				for (int j = 0; j <= v.size(); j++) {
					vector<int> v1 = v;
					v1.insert(v1.begin() + j, nums[i]);
					tmp.push_back(v1);
				}
			}
			res = tmp;
			tmp.clear();
		}
		return res;
	}
};
```

下面是交替使用res和tmp的代码，执行用时立马超过了%93.51的用户。
```C++ []
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res, tmp;
		vector<int> v(1,nums[0]);
		res.push_back(v);
		for (int i = 1; i < nums.size(); i++) {
			if (res.size()) {
				for (auto v : res) {
					for (int j = 0; j <= v.size(); j++) {
						vector<int> v1 = v;
						v1.insert(v1.begin() + j, nums[i]);
						tmp.push_back(v1);
					}
				}
				res.clear();
			}
			else {
				for (auto v : tmp) {
					for (int j = 0; j <= v.size(); j++) {
						vector<int> v1 = v;
						v1.insert(v1.begin() + j, nums[i]);
						res.push_back(v1);
					}
				}
				tmp.clear();
			}
		}
		if (res.size())
			return res;
		else
			return tmp;
		return res;
	}
};
```
