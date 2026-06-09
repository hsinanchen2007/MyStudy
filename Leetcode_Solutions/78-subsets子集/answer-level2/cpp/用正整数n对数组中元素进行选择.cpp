正整数n的二进制表示中每一位为0或1，表示不选或选该位对应的数组元素加入子集中。
不过运行时间有点慢，只超过了17%左右，估计是对n的各位的判断多用了时间，以及多调用了个函数导致每次返回多了拷贝构造的时间，可能不如直接递归来的速度快。
```C++ []
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		n = 1 << n;
		for (int i = 0; i < n; i++)
			res.push_back(get_subset(nums, i));
		return res;
	}
	vector<int> get_subset(vector<int>& nums, int n) {
		vector<int> v;
		int pos = 0;
		while (n) {
			if (n & 1)
				v.push_back(nums[pos]);
			pos++;
			n >>= 1;
		}
		return v;
	}
};
```

把多用的函数改掉，少调用了拷贝构造函数，时间上就超过了50%左右。
```C++ []
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		int n = nums.size();
		n = 1 << n;
		for (int i = 0; i < n; i++){
            vector<int> v;
		    int pos = 0, mask = i;
		    while (mask) {
			    if (mask & 1)
				    v.push_back(nums[pos]);
			    pos++;
			    mask >>= 1;
		    }
			res.push_back(v);
        }
		return res;
	}
};
```
